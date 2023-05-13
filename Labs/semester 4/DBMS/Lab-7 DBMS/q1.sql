CREATE DATABASE college;
USE college;
CREATE TABLE Student (
    snum INT PRIMARY KEY,
    sname VARCHAR(255),
    major VARCHAR(255),
    level VARCHAR(255),
    age INT,
    total_credit INTEGER
);
CREATE TABLE Faculty (
    fid INT PRIMARY KEY,
    fname VARCHAR(255),
    deptid INT
);
CREATE TABLE Class (
    name VARCHAR(255) PRIMARY KEY,
    meets_at VARCHAR(255),
    room VARCHAR(255),
    fid INT,
    total_credits INT,
    FOREIGN KEY (fid) REFERENCES Faculty(fid)
);
CREATE TABLE Enrolled (
    snum INT,
    cname VARCHAR(255),
    grade VARCHAR(255),
    PRIMARY KEY (snum, cname),
    FOREIGN KEY (snum) REFERENCES Student(snum),
    FOREIGN KEY (cname) REFERENCES Class(name)
);

INSERT INTO Class (name, meets_at, room, fid, total_credits)
VALUES (
        'Data Structures',
        'MWF 10',
        'R128',
        489456522,
        3
    ),
    (
        'Database Systems',
        'MWF 12:30-1:45',
        '1320 DCL',
        142519864,
        4
    ),
    (
        'Operating System Design',
        'TuTh 12-1:20',
        '20 AVW',
        489456522,
        5
    ),
    (
        'Archaeology of the Incas',
        'MWF 3-4:15',
        'R128',
        248965255,
        4
    ),
    (
        'Aviation Accident Investigation',
        'TuTh 1-2:50',
        'Q3',
        011564812,
        2
    ),
    (
        'Air Quality Engineering',
        'TuTh 10:30-11:45',
        'R15',
        011564812,
        4
    ),
    (
        'Introductory Latin',
        'MWF 3-4:15',
        'R12',
        248965255,
        3
    ),
    (
        'American Political Parties',
        'TuTh 2-3:15',
        '20 AVW',
        619023588,
        4
    ),
    (
        'Social Cognition',
        'Tu 6:30-8:40',
        'R15',
        159542516,
        4
    ),
    ('Perception', 'MTuWTh 3', 'Q3', 489221823, 3),
    (
        'Multivariate Analysis',
        'TuTh 2-3:15',
        'R15',
        090873519,
        4
    ),
    ('Patent Law', 'F 1-2:50', 'R128', 090873519, 3),
    (
        'Urban Economics',
        'MWF 11',
        '20 AVW',
        489221823,
        2
    ),
    (
        'Organic Chemistry',
        'TuTh 12:30-1:45',
        'R12',
        489221823,
        4
    ),
    (
        'Marketing Research',
        'MW 10-11:15',
        '1320 DCL',
        489221823,
        5
    ),
    (
        'Seminar in American Art',
        'M 4',
        'R15',
        489221823,
        4
    ),
    (
        'Orbital Mechanics',
        'MWF 8',
        '1320 DCL',
        011564812,
        3
    ),
    (
        'Dairy Herd Management',
        'TuTh 12:30-1:45',
        'R128',
        356187925,
        2
    ),
    (
        'Communication Networks',
        'MW 9:30-10:45',
        '20 AVW',
        141582651,
        3
    ),
    (
        'Optical Electronics',
        'TuTh 12:30-1:45',
        'R15',
        254099823,
        4
    ),
    (
        'Intoduction to Math',
        'TuTh 8-9:30',
        'R128',
        489221823,
        5
    )
INSERT INTO faculty (fid, fname, deptid)
VALUES (142519864, 'Ivana Teach', 20),
    (242518965, 'James Smith', 68),
    (141582651, 'Mary Johnson', 20),
    (011564812, 'John Williams', 68),
    (254099823, 'Patricia Jones', 68),
    (356187925, 'Robert Brown', 12),
    (489456522, 'Linda Davis', 20),
    (287321212, 'Michael Miller', 12),
    (248965255, 'Barbara Wilson', 12),
    (159542516, 'William Moore', 33),
    (090873519, 'Elizabeth Taylor', 11),
    (486512566, 'David Anderson', 20),
    (619023588, 'Jennifer Thomas', 11),
    (489221823, 'Richard Jackson', 33),
    (548977562, 'Ulysses Teach', 20);
INSERT INTO student (snum, sname, major, level, age)
VALUES (051135593, 'Maria White', 'English', 'SR', 21),
    (
        060839453,
        'Charles Harris',
        'Architecture',
        'SR',
        22
    ),
    (099354543, 'Susan Martin', 'Law', 'JR', 20),
    (
        112348546,
        'Joseph Thompson',
        'Computer Science',
        'SO',
        19
    ),
    (
        115987938,
        'Christopher Garcia',
        'Computer Science',
        'JR',
        20
    ),
    (
        132977562,
        'Angela Martinez',
        'History',
        'SR',
        20
    ),
    (
        269734834,
        'Thomas Robinson',
        'Psyhcology',
        'SO',
        18
    ),
    (
        280158572,
        'Margaret Clark',
        'Animal Science',
        'FR',
        18
    ),
    (
        301221823,
        'Juan Rodriguez',
        'Psyhcology',
        'JR',
        20
    ),
    (318548912, 'Dorthy Lewis', 'Finance', 'FR', 18),
    (
        320874981,
        'Daniel Lee',
        'Electrical Engineering',
        'FR',
        17
    ),
    (
        322654189,
        'Lisa Walker',
        'Computer Science',
        'SO',
        17
    ),
    (
        348121549,
        'Paul Hall',
        'Computer Science',
        'JR',
        18
    ),
    (351565322, 'Nancy Allen', 'Accounting', 'JR', 19),
    (451519864, 'Mark Young', 'Finance', 'FR', 18),
    (
        455798411,
        'Luis Hernandez',
        'Electrical Engineering',
        'FR',
        17
    ),
    (
        462156489,
        'Donald King',
        'Mechanical Engineering',
        'SO',
        19
    ),
    (
        550156548,
        'George Wright',
        'Education',
        'SR',
        21
    ),
    (
        552455318,
        'Ana Lopez',
        'Computer Engineering',
        'SR',
        19
    ),
    (
        556784565,
        'Kenneth Hill',
        'Civil Engineering',
        'SR',
        21
    ),
    (
        567354612,
        'Karen Scott',
        'Computer Engineering',
        'FR',
        18
    ),
    (
        573284895,
        'Steven Green',
        'Kinesiology',
        'SO',
        19
    ),
    (574489456, 'Betty Adams', 'Economics', 'JR', 20),
    (
        578875478,
        'Edward Baker',
        'Veterinary Medicine',
        'SR',
        21
    )

    
insert into enrolled(snum, cname, grade)
VALUES (112348546, 'Database Systems', 'A'),
    (115987938, 'Database Systems', 'B'),
    (348121549, 'Database Systems', 'F'),
    (322654189, 'Database Systems', null),
    (552455318, 'Database Systems', 'C'),
    (455798411, 'Operating System Design', 'A'),
    (552455318, 'Operating System Design', 'A'),
    (567354612, 'Operating System Design', 'B'),
    (112348546, 'Operating System Design', 'C'),
    (115987938, 'Operating System Design', 'F'),
    (322654189, 'Operating System Design', 'F'),
    (567354612, 'Data Structures', 'F'),
    (552455318, 'Communication Networks', 'F'),
    (455798411, 'Optical Electronics', 'F'),
    (301221823, 'Perception', 'A'),
    (301221823, 'Social Cognition', 'B'),
    (301221823, 'American Political Parties', 'C'),
    (556784565, 'Air Quality Engineering', 'D'),
    (099354543, 'Patent Law', 'A'),
    (574489456, 'Urban Economics', 'F');






DELIMITER //
CREATE FUNCTION getno_student(faculty_name VARCHAR(55),course_name VARCHAR(55))
RETURNS INT 
DETERMINISTIC
READS SQL DATA
BEGIN
    DECLARE no_of_students INT;
    SELECT COUNT(DISTINCT snum) INTO no_of_students
    FROM enrolled 
    WHERE cname in (SELECT DISTINCT name from class where class.name = course_name and fid in
    (select fid from faculty where fname = faculty_name));
    return no_of_students;
END; //
DELIMITER ;

SELECT faculty.fname,getno_student(faculty.fname,name) as no_of_students
from faculty , class having no_of_students>1;

-- select fid,cname,count(snum) as noofstudent from enrolled,class where cname = name group by cname;



DELIMITER //
CREATE FUNCTION get_f_grades(course_name VARCHAR(55))
RETURNS INT
DETERMINISTIC
READS SQL DATA
BEGIN
    DECLARE num_f_grades INT;
    SELECT COUNT(*) INTO num_f_grades
    FROM enrolled
    WHERE cname = course_name AND grade = 'F';
    RETURN num_f_grades;
END; //
DELIMITER ;


SELECT DISTINCT faculty.fname
FROM faculty
JOIN class ON faculty.fid = class.fid
JOIN (
    SELECT cname
    FROM enrolled
    WHERE get_f_grades(enrolled.cname) >1
) AS f_grades ON class.name = f_grades.cname













-- SELECT faculty.fname 
-- FROM faculty
-- INNER JOIN class ON faculty.fid = class.fid
-- INNER JOIN enrolled ON class.name = enrolled.cname
-- WHERE enrolled.grade = 'F'
-- GROUP BY faculty.fname, enrolled.cname
-- HAVING get_f_grades(enrolled.cname) > 1;

-- SELECT DISTINCT faculty.fname
-- FROM faculty
-- JOIN class ON faculty.fid = class.fid
-- JOIN (
--     SELECT cname, COUNT(*) AS num_f_grades
--     FROM enrolled
--     WHERE grade = 'F'
--     GROUP BY cname
--     HAVING COUNT(*) > 1
-- ) AS f_grades ON class.name = f_grades.cname
