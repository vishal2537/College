-- 1--
SELECT DISTINCT name FROM class WHERE room = '20 AVW' OR (SELECT count(*) FROM enrolled WHERE enrolled.cname = class.name) >=5;

--2--
SELECT room, COUNT(*) AS NUMBER_OF_COURSES FROM class GROUP BY room;

--3--
SELECT faculty.fid ,fname,COUNT(name) as NUMBER_OF_CLASSES FROM faculty LEFT JOIN class ON faculty.fid = class.fid GROUP BY faculty.fid;

--4--
CREATE view ENROLLED_STUDENTS AS SELECT cname,enrolled.snum FROM enrolled,student WHERE  enrolled.snum = student.snum;

SELECT room, class.name, COUNT(ENROLLED_STUDENTS.snum) AS NUMBER_OF_ENROLLED FROM class LEFT JOIN (ENROLLED_STUDENTS) ON ENROLLED_STUDENTS.cname = class.cname GROUP BY class.name;

--5--
SELECT * FROM faculty WHERE deptid = 20 AND fid IN(SELECT fid FROM class WHERE room ='R128');

--6--
SELECT major, MAX(age) AS MAXIMUM_AGE FROM student GROUP BY major;

--7--
SELECT sname AS STUDENT_NAME FROM student WHERE sname LIKE '%son%' UNION SELECT fname AS FACULTY_NAME FROM faculty WHERE fname LIKE '%son%';


---------------------------------------


--8
SELECT supervisor FROM employees_and_supervisors WHERE person = 'Ravi';


--9
SELECT supervisor FROM employees_and_supervisors WHERE person = (SELECT supervisor FROM employees_and_supervisors WHERE person = 'Ravi');


--10--


select employees_and_supervisors.supervisor from employees_and_supervisors where person="Ravi" union select second.supervisor from employees_and_supervisors first,employees_and_supervisors second where first.supervisor=second.person;
























-- WITH RECURSIVE supervisors (person, supervisor) AS (
--   SELECT person, supervisor
--   FROM employees_and_supervisors
--   WHERE person = 'Ravi'
--   UNION ALL
--   SELECT e.person, e.supervisor
--   FROM employees_and_supervisors e
--   JOIN supervisors s ON e.person = s.supervisor
-- )
-- SELECT * FROM supervisors;
