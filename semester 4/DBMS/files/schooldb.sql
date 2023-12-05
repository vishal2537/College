-- MariaDB dump 10.19  Distrib 10.6.11-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: school
-- ------------------------------------------------------
-- Server version	10.6.11-MariaDB-1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `class`
--

DROP TABLE IF EXISTS `class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `class` (
  `name` varchar(40) NOT NULL,
  `meets_at` varchar(40) DEFAULT NULL,
  `room` varchar(40) DEFAULT NULL,
  `fid` int(11) DEFAULT NULL,
  PRIMARY KEY (`name`),
  KEY `fid` (`fid`),
  CONSTRAINT `class_ibfk_1` FOREIGN KEY (`fid`) REFERENCES `faculty` (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class`
--

LOCK TABLES `class` WRITE;
/*!40000 ALTER TABLE `class` DISABLE KEYS */;
INSERT INTO `class` VALUES ('Air Quality Engineering','TuTh 10:30-11:45','R15',11564812),('American Political Parties','TuTh 2-3:15','20 AVW',619023588),('Archaeology of the Incas','MWF 3-4:15','R128',248965255),('Aviation Accident Investigation','TuTh 1-2:50','Q3',11564812),('Communication Networks','MW 9:30-10:45','20 AVW',141582651),('Dairy Herd Management','TuTh 12:30-1:45','R128',356187925),('Data Structures','MWF 10','R128',489456522),('Database Systems','MWF 12:30-1:45','1320 DCL',142519864),('Intoduction to Math','TuTh 8-9:30','R128',489221823),('Introductory Latin','MWF 3-4:15','R12',248965255),('Marketing Research','MW 10-11:15','1320 DCL',489221823),('Multivariate Analysis','TuTh 2-3:15','R15',90873519),('Operating System Design','TuTh 12-1:20','20 AVW',489456522),('Optical Electronics','TuTh 12:30-1:45','R15',254099823),('Orbital Mechanics','MWF 8','1320 DCL',11564812),('Organic Chemistry','TuTh 12:30-1:45','R12',489221823),('Patent Law','F 1-2:50','R128',90873519),('Perception','MTuWTh 3','Q3',489221823),('Seminar in American Art','M 4','R15',489221823),('Social Cognition','Tu 6:30-8:40','R15',159542516),('Urban Economics','MWF 11','20 AVW',489221823);
/*!40000 ALTER TABLE `class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enrolled`
--

DROP TABLE IF EXISTS `enrolled`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `enrolled` (
  `snum` int(11) DEFAULT NULL,
  `cname` varchar(40) DEFAULT NULL,
  KEY `snum` (`snum`),
  KEY `cname` (`cname`),
  CONSTRAINT `enrolled_ibfk_1` FOREIGN KEY (`snum`) REFERENCES `student` (`snum`),
  CONSTRAINT `enrolled_ibfk_2` FOREIGN KEY (`cname`) REFERENCES `class` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enrolled`
--

LOCK TABLES `enrolled` WRITE;
/*!40000 ALTER TABLE `enrolled` DISABLE KEYS */;
INSERT INTO `enrolled` VALUES (112348546,'Database Systems'),(115987938,'Database Systems'),(348121549,'Database Systems'),(322654189,'Database Systems'),(552455318,'Database Systems'),(455798411,'Operating System Design'),(552455318,'Operating System Design'),(567354612,'Operating System Design'),(112348546,'Operating System Design'),(115987938,'Operating System Design'),(322654189,'Operating System Design'),(567354612,'Data Structures'),(552455318,'Communication Networks'),(455798411,'Optical Electronics'),(301221823,'Perception'),(301221823,'Social Cognition'),(301221823,'American Political Parties'),(556784565,'Air Quality Engineering'),(99354543,'Patent Law'),(574489456,'Urban Economics');
/*!40000 ALTER TABLE `enrolled` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `faculty`
--

DROP TABLE IF EXISTS `faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `faculty` (
  `fid` int(11) NOT NULL,
  `fname` varchar(40) DEFAULT NULL,
  `deptid` int(11) DEFAULT NULL,
  PRIMARY KEY (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `faculty`
--

LOCK TABLES `faculty` WRITE;
/*!40000 ALTER TABLE `faculty` DISABLE KEYS */;
INSERT INTO `faculty` VALUES (11564812,'John Williams',68),(90873519,'Elizabeth Taylor',11),(141582651,'Mary Johnson',20),(142519864,'Ivana Teach',20),(159542516,'William Moore',33),(242518965,'James Smith',68),(248965255,'Barbara Wilson',12),(254099823,'Patricia Jones',68),(287321212,'Michael Miller',12),(356187925,'Robert Brown',12),(486512566,'David Anderson',20),(489221823,'Richard Jackson',33),(489456522,'Linda Davis',20),(548977562,'Ulysses Teach',20),(619023588,'Jennifer Thomas',11);
/*!40000 ALTER TABLE `faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `snum` int(11) NOT NULL,
  `sname` varchar(40) DEFAULT NULL,
  `major` varchar(40) DEFAULT NULL,
  `level` varchar(40) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  PRIMARY KEY (`snum`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (51135593,'Maria White','English','SR',21),(60839453,'Charles Harris','Architecture','SR',22),(99354543,'Susan Martin','Law','JR',20),(112348546,'Joseph Thompson','Computer Science','SO',19),(115987938,'Christopher Garcia','Computer Science','JR',20),(132977562,'Angela Martinez','History','SR',20),(269734834,'Thomas Robinson','Psychology','SO',18),(280158572,'Margaret Clark','Animal Science','FR',18),(301221823,'Juan Rodriguez','Psychology','JR',20),(318548912,'Dorthy Lewis','Finance','FR',18),(320874981,'Daniel Lee','Electrical Engineering','FR',17),(322654189,'Lisa Walker','Computer Science','SO',17),(348121549,'Paul Hall','Computer Science','JR',18),(351565322,'Nancy Allen','Accounting','JR',19),(451519864,'Mark Young','Finance','FR',18),(455798411,'Luis Hernandez','Electrical Engineering','FR',17),(462156489,'Donald King','Mechanical Engineering','SO',19),(550156548,'George Wright','Education','SR',21),(552455318,'Ana Lopez','Computer Engineering','SR',19),(556784565,'Kenneth Hill','Civil Engineering','SR',21),(567354612,'Karen Scott','Computer Engineering','FR',18),(573284895,'Steven Green','Kinesiology','SO',19),(574489456,'Betty Adams','Economics','JR',20),(578875478,'Edward Baker','Veterinary Medicine','SR',21);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-01-11 20:31:24
