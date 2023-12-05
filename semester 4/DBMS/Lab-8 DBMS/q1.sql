
-- function to get totalCredit for every student who is enrolled in atleast one course
ALTER TABLE student ADD COLUMN total_credits INTEGER DEFAULT 0;

delimiter //
create function getTotalCredit(studentId int) 
returns int 
deterministic 
begin 
  declare value int; 
  select sum(credits) into value from enrolled,class where enrolled.snum=studentId and cname=name and grade is not null and grade<>"F";
  return value;
end//
delimiter ;

update student set total_credits= case when getTotalCredit(snum) is not null then getTotalCredit(snum) else 0 end;

-- Q1

create trigger update_total_credits
after update on enrolled
for each row
begin 
    update student 
    set total_credits = (
        select sum(
            case when grade = 'F' or grade is null then 0
            else class.credits
            end
        )
        from enrolled inner join class on enrolled.cname = class.name
        where enrolled.snum = student.snum
    )
    where snum = new.snum;
end;

-- Q2

create table ready_students(
    snum integer primary key
);

create trigger update_ready_students
after update on student 
for each row
begin
    if new.total_credits > 10 and not exists
    (
        select snum from ready_students where snum = new.snum
    )
    then insert into ready_students(snum) values (new.snum);
    elseif new.total_credits <= 10 and exists
    (
        select snum from ready_students where snum = new.snum
    )
    then delete from ready_students where snum = new.snum;
    end if;
end;










-- CREATE TRIGGER update_ready_students
-- AFTER UPDATE ON Student
-- FOR EACH ROW
-- BEGIN
--   IF NEW.total_credits > 10 THEN
--     INSERT INTO Ready_Students (snum) VALUES (NEW.snum);
--   ELSE
--     DELETE FROM Ready_Students WHERE snum = NEW.snum;
--   END IF;
-- END;





















-- UPDATE Enrolled SET grade = (CASE
--                                 WHEN grade = 'A+' THEN 'A'
--                                 WHEN grade = 'B+' THEN 'B'
--                                 WHEN grade = 'C+' THEN 'C'
--                                 ELSE grade
--                              END);




-- In MySQL, a trigger is a special type of stored program that is automatically executed 
-- in response to certain events or changes occurring in the database. Triggers can be used 
-- to enforce business rules, audit changes, or perform custom actions when data is inserted, updated, or
--  deleted from a table.

-- Triggers can be defined to activate before or after an event, and they can be set to execute 
-- for each row affected by the event or just once per event. They can also be used to modify the 
-- data being inserted, updated, or deleted.

-- MySQL supports triggers for the following events:

-- INSERT: Triggered when a new row is inserted into a table
-- UPDATE: Triggered when an existing row is updated in a table
-- DELETE: Triggered when a row is deleted from a table
-- Triggers are created using the CREATE TRIGGER statement, and they can be managed using 
-- the SHOW TRIGGERS and DROP TRIGGER statements.