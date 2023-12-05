1-->

-- SELECT MIN(age) FROM student s LEFT JOIN enrolled e ON s.snum = e.snum   
-- WHERE major = 'Finance' or cname IN (SELECT name FROM class WHERE fid IN (SELECT fid from faculty where fname = 'Linda Davis'));  


-- with minAge(Age) as (select min(age) from student) 
-- select distinct sname from student,minAge,enrolled 
-- where student.snum=enrolled.snum and student.age=minAge.Age 
-- and (student.major="Finance" or exists(select name from class,faculty where class.fid=faculty.fid 
-- and faculty.fname="Linda Davis"));

SELECT sname FROM Student WHERE age = (SELECT MIN(age) FROM Student)
AND (major = 'Finance' OR snum IN (
  SELECT snum FROM Enrolled WHERE cname IN (
    SELECT cname FROM Class WHERE fid IN (
      SELECT fid FROM Faculty WHERE fname = 'Linda Davis'
    )
  )
));



2-->

SELECT fname FROM faculty WHERE NOT EXISTS (SELECT room FROM class 
WHERE NOT EXISTS ( SELECT * FROM class c WHERE c.room = class.room AND c.fid = faculty.fid));


-- with total_room(value) as
-- (select count(distinct room) as value from Class),
-- fac_and_room (fname, value) as
-- (select faculty.fname, count(distinct room) as value from Faculty, Class 
-- where Faculty.fid = Class.fid group by Faculty.fid)
-- select fname, fac_and_room.value from fac_and_room, total_room
-- where fac_and_room.value = total_room.value;


3-->
with totalClass(fname,fid,NoOfCourses) as (select faculty.fname,faculty.fid,count(class.name) as NoOfCourses from faculty,class 
where faculty.fid=class.fid group by faculty.fid), 
minClass(value) as (select min(NoOfCourses) from totalClass) 
select fname from totalClass,minClass where totalClass.NoOfCourses=minClass.value;


4-->
select fname from faculty where fid not in (select fid from class);

5-->
SELECT age, level FROM student GROUP BY age, level HAVING count(*) >= all (SELECT count(*) FROM student s WHERE s.age = student.age GROUP BY level);

6-->
select name from class where room = 'R128' and class.name in (select cname from enrolled);

7-->
select distinct name,meets_at from class where name in (select cname from enrolled);

8-->
select snum from student where level = 'JR' and snum in(select snum from enrolled where cname in(select name from class where room = 'R128'));

9-->
select sname from student where age>18 and level = 'SR' and major not like '%Engineering';

10-->
select name from class where class.name not in (select cname from enrolled);