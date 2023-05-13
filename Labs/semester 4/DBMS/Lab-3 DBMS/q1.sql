1-->
SELECT level , AVG(age) AS average_age FROM student group by level;


2-->
SELECT level , AVG(age) AS average_age FROM student Where level != 'JR' group by level;


3-->
select fname , count(faculty.fid) as count_classes from faculty, class where faculty.fid = class.fid group by (faculty.fid);


4-->
select student.sname from student,enrolled where student.snum=enrolled.snum && cname="Database Systems" except select student.sname from student,enrolled where student.snum=enrolled.snum && cname="Operating System";



select sname from student where snum in(SELECT snum FROM enrolled where cname = 'Database Systems')
except (SELECT sname from student where snum IN(SELECT snum FROM enrolled where cname = 'Operating System'));


5-->
SELECT AVG(age) FROM Student s JOIN Enrolled e ON s.snum = e.snum GROUP BY e.cname HAVING COUNT(*) >= 2;

select enrolled.cname,avg(student.age) 
as average from student,enrolled 
where student.snum=enrolled.snum 
group by enrolled.cname having count(student.snum)>1;


6-->
SELECT fid FROM Class GROUP BY fid HAVING COUNT(*) > 1;


select faculty.fname,count(faculty.fid) 
as count_Courses from faculty,class 
where faculty.fid=class.fid 
group by faculty.fid having count(faculty.fid)>1;



7-->
SELECT snum FROM Enrolled GROUP BY snum HAVING COUNT(*) > 1;


select student.snum,count(enrolled.cname) 
as noOfCourses from student,enrolled 
where student.snum=enrolled.snum 
group by enrolled.snum having count(enrolled.cname)>1;

8-->
SELECT * FROM student ORDER BY age ASC;


9-->
select sname,snum from student where major like "%Engineering";


SELECT snum, sname FROM Student 
WHERE major 
IN ('Electrical Engineering','Mechanical Engineering','Computer Engineering','Civil Engineering');


10-->
select major,count(student.snum) as NoOfStudents from student where major like "%Engineering" group by major;


SELECT major, COUNT(snum) as NoOfStudents FROM Student GROUP BY major;