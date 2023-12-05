--1-->
DELIMITER //
CREATE FUNCTION getnumber_student(faculty_id INT,course_name VARCHAR(55))
RETURNS INT 
DETERMINISTIC
BEGIN
    DECLARE no_of_students INT;
    SELECT COUNT(DISTINCT snum) INTO no_of_students
    FROM enrolled , class where (class.fid = faculty_id) 
    and (cname = name) and (cname = course_name);  
    return no_of_students;
END; //
DELIMITER ;

-- query
SELECT faculty.fname,getnumber_student(faculty.fid,name) as no_of_students
from faculty,class where getnumber_student(faculty.fid,name)>1;

--2-->
DELIMITER //
CREATE FUNCTION get_f_grades(course_name VARCHAR(55))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE num_f_grades INT;
    SELECT COUNT(*) INTO num_f_grades
    FROM enrolled
    WHERE cname = course_name AND grade = 'F';
    RETURN num_f_grades;
END; //
DELIMITER ;

-- query
SELECT DISTINCT fname
FROM faculty,class
where faculty.fid = class.fid and get_f_grades(name) >1;