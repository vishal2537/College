import java.util.Scanner;

class user {
    protected String name;
    protected int birthYear;
    protected int userId;
    protected String dateOfBirth;

    user() {
    }

    public user(String name, int birthYear, int userId, String dateOfBirth) {
        this.name = name;
        this.birthYear = birthYear;
        this.dateOfBirth = dateOfBirth;
        this.userId = userId;
    }

    public void setDetails(String name, int birthyear, int userid, String dateOfBirth) {
        this.name = name;
        this.birthYear = birthyear;
        this.dateOfBirth = dateOfBirth;
        this.userId = userid;
    }

    public void getDetail(int userid) {
        if (this.userId == userid) {
            System.out.println("\t\tNAME : " + name);
            System.out.println("\t\tDATEOFBIRTH : " + dateOfBirth);
            System.out.println("\t\tBIRTHYEAR : " + birthYear);
            System.out.println("\t\tUSERID : " + userId);

        }
    }

    public void getDetails(int birthYear) {
        if (this.birthYear == birthYear) {
            System.out.println("\t\tNAME : " + name);
            System.out.println("\t\tDATEOFBIRTH : " + dateOfBirth);
            System.out.println("\t\tBIRTHYEAR : " + birthYear);
            System.out.println("\t\tUSERID : " + userId);
        }
    }

    public int getUserId() {
        return userId;
    }
}

class student extends user {
    private int rollNumber;
    private int semester;
    private float cpi;

    student() {
    }

    public void setDetails(String name, int birthyear, int userid, int rollnumber, int semester, Float cpi,
            String dateOfBirth) {
        super.setDetails(name, birthyear, userid, dateOfBirth);
        this.rollNumber = rollnumber;
        this.semester = semester;
        this.cpi = cpi;
    }

    public student(String name, int birthyear, int userid, int rollnumber, int semester, Float cpi,
            String dateOfBirth) {
        super(name, birthyear, userid, dateOfBirth);
        this.rollNumber = rollnumber;
        this.semester = semester;
        this.cpi = cpi;
    }

    public void getDetails(int birthyear) {
        if (this.birthYear == birthyear) {
            super.getDetails(birthyear);
            System.out.println("\t\tROLL NUMBER : " + rollNumber);
            System.out.println("\t\tSEMESTER : " + semester);
            System.out.println("\t\tCPI : " + cpi);
        }
    }

    public void getDetail(int userId, int rollno, int birthYear) {
        if (this.userId == userId && this.rollNumber == rollno && this.birthYear == birthYear) {
            super.getDetails(birthYear);
            System.out.println("\t\tROLL NUMBER : " + rollNumber);
            System.out.println("\t\tSEMESTER : " + semester);
            System.out.println("\t\tCPI : " + cpi);
        }
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public int getuserId() {
        return this.userId;
    }

}

class faculty extends user {
    private int employeeID;
    private String departmentName;
    private int noOfPubliction;

    public faculty(int employeeID, String departmentName, int noofpublication, int birthyear, int userid, String name,
            String dateOfBirth) {
        super(name, birthyear, userid, dateOfBirth);
        this.employeeID = employeeID;
        this.departmentName = departmentName;
        this.noOfPubliction = noofpublication;
    }

    public faculty() {
    }

    public void setdetails(String name, int birthyear, int userid, int employeeid, String departmentname,
            int noofpublication, String dateOfBirth) {
        super.setDetails(name, birthyear, userid, dateOfBirth);
        this.employeeID = employeeid;
        this.departmentName = departmentname;
        this.noOfPubliction = noofpublication;
    }

    public void checkDepartmentNamee(faculty f1, faculty f2) {
        if (f1.departmentName == f2.departmentName) {
            System.out.println("SAME DEPARTMENT!");
        } else {
            System.out.println("DIFFERENT DEPARTMENT!");
        }
    }

    public boolean checkEmployeeId(faculty f1, faculty f2) {
        return (f1.employeeID == f2.employeeID);
    }

    public void getDetails(int birthYear) {
        if (this.birthYear == birthYear) {
            super.getDetails(birthYear);
            System.out.println("\t\tEMPLOYEEID : " + employeeID);
            System.out.println("\t\tDEPARTMENT NAME : " + departmentName);
            System.out.println("\t\tNOOFPUBLICATION : " + noOfPubliction);
        }
    }

    public void getDetail(int userid, int employeeID, int birthYear) {
        if (this.userId == userid && this.employeeID == employeeID && this.birthYear == birthYear) {
            super.getDetails(birthYear);
            System.out.println("\t\tEMPLOYEEID : " + employeeID);
            System.out.println("\t\tDEPARTMENT NAME : " + departmentName);
            System.out.println("\t\tNOOFPUBLICATION : " + noOfPubliction);
        }
    }

    public int getuserId() {
        return this.userId;
    }

    public int getEmployeeID() {
        return employeeID;
    }
}

class staff extends user {
    private int employeeID;
    private String sectionName;
    private String designation;

    staff() {
    }

    public staff(String name, int birthyear, int userid, int employeeid, String setion, String designation,
            String dateOfBirth) {
        super(name, birthyear, userid, dateOfBirth);
        this.employeeID = employeeid;
        this.sectionName = setion;
        this.designation = designation;
    }

    public void setdetails(String name, int birthyear, int userid, int employeeid, String setion, String designation,
            String dateOfBirth) {
        super.setDetails(name, birthyear, userid, dateOfBirth);
        this.employeeID = employeeid;
        this.sectionName = setion;
        this.designation = designation;
    }

    public void getDetail(int birthYear) {
        if (this.birthYear == birthYear) {
            super.getDetails(birthYear);
            System.out.println("\t\tEMPLOYEEID : " + employeeID);
            System.out.println("\t\tSECTIONNAME : " + sectionName);
            System.out.println("\t\tDESIGNATION : " + designation);
        }
    }

    public void getDetails(int userId, int employeeID, int birthYear) {
        if (this.userId == userId && this.employeeID == employeeID && this.birthYear == birthYear) {
            super.getDetails(birthYear);
            System.out.println("\t\tEMPLOYEEID : " + employeeID);
            System.out.println("\t\tSECTIONNAME : " + sectionName);
            System.out.println("\t\tDESIGNATION : " + designation);
        }
    }

    public void checkDesignation(staff s1, staff s2) {
        if (s1.designation == s2.designation) {
            System.out.println("SAME DESIGNATION!");
        } else {
            System.out.println("DIFFERENT DESIGNATION !");
        }
    }

    public int getuserId() {
        return this.userId;

    }

    public int getEmployeeID() {
        return employeeID;
    }
}

public class assignment6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        student[] stud = new student[1000];
        faculty[] fac = new faculty[1000];
        staff[] staf = new staff[1000];

        int i = 0, j = 0, k = 0;
        while (true) {
            System.out.println("\t1 - FACULTY ");
            System.out.println("\t2 - STUDENT ");
            System.out.println("\t3 - STAFF ");
            System.out.println("\t4 - EXIT ");
            System.out.print("ENTER YOUR CHOICE : ");
            int ch = input.nextInt();
            input.nextLine();

            if (ch == 1) {
                System.out.println("\t0 - SET DETAILS BY USING CONSTRUCTORS ");
                System.out.println("\t1 - SET DETAILS BY USING METHOD ");
                System.out.println("\t2 - GET DEGTAILS BY USING BIRTHYEAR ");
                System.out.println("\t3 - GET DETAILS BY USING DIFFERNT PARAMETERS ");
                System.out.println("\t4 - COMPARE DEPARTMENT OF TWO FACULTY");
                System.out.print("ENTER YOUR CHOICE : ");
                int ch1 = input.nextInt();
                input.nextLine();

                if (ch1 == 0) {
                    System.out.print("ENTER NAME : ");
                    String name = input.nextLine();

                    System.out.print("ENTER DATEOFBIRTH : ");
                    String dateOfBirth = input.nextLine();
                    System.out.print("ENTER BIRTH YEAR : ");
                    int birthYear = input.nextInt();

                    System.out.print("ENTER USERID : ");
                    int userId = input.nextInt();

                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < k; k2++) {
                            if (fac[k2] != null && fac[k2].getUserId() == userId) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER USERID : ");
                                userId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER EMPLOYEEID : ");
                    int employeeId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < k; k2++) {
                            if (fac[k2] != null && fac[k2].getEmployeeID() == employeeId) {
                                System.out.println("EMPLOYEEID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER EMPLOYEEID : ");
                                employeeId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    input.nextLine();
                    System.out.print("ENTER DEPARTMENT NAME: ");
                    String departmentName = input.nextLine();
                    System.out.print("ENTER NUMBER OF PUBLICATIONS : ");
                    int noOfPublications = input.nextInt();
                    input.nextLine();

                    faculty obj = new faculty(employeeId, departmentName, noOfPublications, birthYear, userId, name,
                            dateOfBirth);
                    fac[k] = obj;
                    k++;
                } else if (ch1 == 1) {
                    System.out.print("ENTER NAME : ");
                    String name = input.nextLine();
                    System.out.print("ENTER DATEOFBIRTH : ");
                    String dateOfBirth = input.nextLine();
                    System.out.print("ENTER BIRTH YEAR : ");
                    int birthYear = input.nextInt();

                    System.out.print("ENTER USERID : ");
                    int userId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < k; k2++) {
                            if (fac[k2] != null && fac[k2].getUserId() == userId) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER USERID : ");
                                userId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER EMPLOYEEID : ");
                    int employeeId = input.nextInt();

                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < k; k2++) {
                            if (fac[k2] != null && fac[k2].getEmployeeID() == employeeId) {
                                System.out.println("EMPLOYEEID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER EMPLOYEEID : ");
                                employeeId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    input.nextLine();
                    System.out.print("ENTER DEPARTMENT NAME : ");
                    String departmentName = input.nextLine();
                    System.out.print("ENTER NUMBER OF PUBLICATION : ");
                    int noOfPublications = input.nextInt();
                    input.nextLine();

                    faculty obj = new faculty();
                    fac[k] = obj;
                    fac[k].setdetails(name, birthYear, userId, employeeId, departmentName, noOfPublications,
                            dateOfBirth);
                    k++;
                } else if (ch1 == 2) {
                    System.out.print("ENTER BIRTH YEAR TO GET DETAILS : ");
                    int year = input.nextInt();
                    input.nextLine();

                    for (int l = 0; l < k; l++) {
                        fac[l].getDetails(year);
                    }
                } else if (ch1 == 3) {
                    System.out.println("ENTER USERID,EMPLOYEEID,BIRTH YEAR TO GET DETAILS");
                    int userId = input.nextInt();
                    int employeeID = input.nextInt();
                    int birthYear = input.nextInt();
                    for (int l = 0; l < k; l++) {
                        fac[l].getDetail(userId, employeeID, birthYear);
                    }
                } else if (ch1 == 4) {
                    System.out.print("ENTER USERID OF USER 1 : ");
                    int id1 = input.nextInt();
                    System.out.print("ENTER USERID OF USER 2 : ");
                    int id2 = input.nextInt();
                    faculty f1 = null, f2 = null;

                    for (int l = 0; l < k; l++) {
                        if (fac[l] == null) {
                            continue;
                        }
                        if (id1 == (fac[l].getuserId())) {
                            f1 = fac[l];
                        }
                    }
                    for (int l = 0; l < k; l++) {
                        if (fac[l] == null) {
                            continue;
                        }

                        if (id2 == (fac[l].getuserId())) {
                            f2 = fac[l];
                        }
                    }
                    if (f1 != null && f2 != null) {
                        f1.checkDepartmentNamee(f1, f2);
                    }
                } else {
                    System.out.println("INVALID CHOICE ");
                }
            } else if (ch == 2) {
                System.out.println("\t0 - SET DETAILS BY USING CONSTRUCTOR");
                System.out.println("\t1 - SET DETAILS BY USING METHOD");
                System.out.println("\t2 - GET DETAILS BY USING BIRTH YEAR");
                System.out.println("\t3 - GET DETAILS BY USING DIFFERENT PARAMETERS");

                System.out.print("ENTER YOUR CHOICE : ");
                int ch1 = input.nextInt();
                if (ch1 == 0) {
                    System.out.print("ENTER NAME : ");
                    input.nextLine();
                    String name = input.nextLine();
                    System.out.print("ENTER DATEOFBIRTH : ");
                    String dateOfBirth = input.nextLine();
                    System.out.print("ENTER BIRTH YEAR : ");
                    int birthYear = input.nextInt();
                    input.nextLine();

                    System.out.print("ENTER USERID : ");
                    int userId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < i; k2++) {
                            if (stud[k2] != null && stud[k2].getUserId() == userId) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER USERID : ");
                                userId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER ROLL NUMBER : ");
                    int rollno = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < i; k2++) {
                            if (stud[k2] != null && stud[k2].getRollNumber() == rollno) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER ROLLNUMBER : ");
                                rollno = input.nextInt();
                                flag = 1;
                            }

                        }
                        if (flag == 0) {
                            break;
                        }

                    }

                    System.out.print("ENTER SEMESTER : ");
                    int semester = input.nextInt();
                    System.out.print("Enter CPI : ");
                    float cpi = input.nextFloat();

                    student obj = new student(name, birthYear, userId, rollno, semester, cpi, dateOfBirth);
                    stud[i] = obj;
                    i++;

                } else if (ch1 == 1) {
                    System.out.print("ENTER NAME : ");
                    input.nextLine();
                    String name = input.nextLine();
                    System.out.print("ENTER DATEOFBIRTH : ");
                    String dateOfBirth = input.nextLine();
                    System.out.print("ENTER BIRTH YEAR : ");
                    int birthYear = input.nextInt();

                    System.out.print("ENTER USERID : ");
                    int userId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < i; k2++) {
                            if (stud[k2] != null && stud[k2].getUserId() == userId) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER USERID : ");
                                userId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER ROLL NUMBER : ");
                    int rollno = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < i; k2++) {
                            if (stud[k2] != null && stud[k2].getRollNumber() == rollno) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER ROLLNUMBER : ");
                                rollno = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER SEMESTER : ");
                    int semester = input.nextInt();
                    System.out.print("ENTER CPI: ");
                    float cpi = input.nextFloat();

                    student obj = new student();
                    stud[i] = obj;
                    stud[i].setDetails(name, birthYear, userId, rollno, semester, cpi, dateOfBirth);
                    i++;
                } else if (ch1 == 2) {
                    System.out.print("ENTER BIRTH YEAR TO GET DETAILS : ");
                    int year = input.nextInt();
                    for (int l = 0; l < i; l++) {
                        stud[l].getDetails(year);
                    }
                } else if (ch1 == 3) {
                    System.out.println("ENTER USERID,Roll-No,BIRTH YEAR TO GET DETAILS");
                    int userId = input.nextInt();
                    int rollno = input.nextInt();
                    int birthYear = input.nextInt();
                    for (int l = 0; l < i; l++) {
                        stud[l].getDetail(userId, rollno, birthYear);
                    }
                } else {
                    System.out.println("INVALID CHOICE ");
                }

            } else if (ch == 3) {
                System.out.println("\t0 - SET DETAILS BY USING CONSTRUCTOR");
                System.out.println("\t1 - SET DETAILS BY USING METHOD");
                System.out.println("\t2 - GET DETAILS BY USING BIRTH YEAR");
                System.out.println("\t3 - GET DETAILS BY USING DIFFERENT PARAMETERS");
                System.out.println("\t4 - COMPARE DESIGNATION BY USING USER ID)");

                System.out.print("ENTER YOUR CHOICE : ");
                int ch1 = input.nextInt();
                input.nextLine();
                if (ch1 == 0) {
                    System.out.print("ENTER NAME : ");
                    String name = input.nextLine();
                    System.out.print("ENTER DATEOFBIRTH : ");
                    String dateOfBirth = input.nextLine();
                    System.out.print("ENTER BIRTH YEAR : ");
                    int birthYear = input.nextInt();

                    System.out.print("ENTER USERID : ");
                    int userId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < j; k2++) {
                            if (staf[k2] != null && staf[k2].getUserId() == userId) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER USERID : ");
                                userId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("Enter EMPLOYEEID : ");
                    int employeeId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < j; k2++) {
                            if (staf[k2] != null && staf[k2].getEmployeeID() == employeeId) {
                                System.out.println("EMPLOYEEID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER EMPLOYEEID : ");
                                employeeId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER SECTION NAME : ");
                    input.nextLine();
                    String sectionName = input.nextLine();
                    System.out.print("ENTER DESIGNATIOIN : ");
                    String designation = input.nextLine();

                    staff obj = new staff(name, birthYear, userId, employeeId, sectionName, designation, dateOfBirth);
                    staf[j] = obj;
                    j++;

                } else if (ch1 == 1) {
                    System.out.print("ENTER NAME : ");
                    String name = input.nextLine();
                    System.out.print("ENTER DATEOFBIRTH : ");
                    String dateOfBirth = input.nextLine();
                    System.out.print("ENTER BIRTH YEAR : ");
                    int birthYear = input.nextInt();

                    System.out.print("ENTER USERID : ");
                    int userId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < j; k2++) {
                            if (staf[k2] != null && staf[k2].getUserId() == userId) {
                                System.out.println("USERID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER USERID : ");
                                userId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("Enter EMPLOYEEID : ");
                    int employeeId = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int k2 = 0; k2 < j; k2++) {
                            if (staf[k2] != null && staf[k2].getEmployeeID() == employeeId) {
                                System.out.println("EMPLOYEEID ALREADY EXIST !!");
                                System.out.print("AGAIN ENTER EMPLOYEEID : ");
                                employeeId = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    System.out.print("ENTER SECTION NAME : ");
                    input.nextLine();
                    String sectionName = input.nextLine();
                    System.out.print("ENTER DESIGNATIOIN : ");
                    String designation = input.nextLine();

                    staff object = new staff();
                    staf[j] = object;
                    staf[j].setdetails(name, birthYear, userId, employeeId, sectionName, designation, dateOfBirth);
                    j++;
                } else if (ch1 == 2) {
                    System.out.print("ENTER BIRTH YEAR TO GET DETAILS : ");
                    int year = input.nextInt();
                    for (int l = 0; l < j; l++) {
                        staf[l].getDetails(year);
                    }
                } else if (ch1 == 3) {
                    System.out.println("ENTER USERID,EMPLOYEEID,BIRTH YEAR TO GET DETAILS");
                    int userId = input.nextInt();
                    int employeeID = input.nextInt();
                    int birthYear = input.nextInt();
                    for (int l = 0; l < j; l++) {
                        staf[l].getDetails(userId, employeeID, birthYear);
                    }
                } else if (ch1 == 4) {
                    System.out.print("ENTER USERID 1 : ");
                    int id1 = input.nextInt();
                    System.out.print("ENTER USERID 2 : ");
                    int id2 = input.nextInt();
                    staff s1 = null, s2 = null;

                    for (int l = 0; l < j; l++) {
                        if (staf[l] == null) {
                            continue;
                        }
                        if (id1 == (staf[l].getuserId())) {
                            s1 = staf[l];
                        }
                    }
                    for (int l = 0; l < j; l++) {
                        if (staf[l] == null) {
                            continue;
                        }

                        if (id2 == (staf[l].getuserId())) {
                            s2 = staf[l];
                        }
                    }
                    if (s1 != null && s2 != null) {
                        s1.checkDesignation(s1, s2);
                    }
                } else {
                    System.out.println("INVALID CHOICE");
                }
            } else if (ch == 4) {
                break;
            } else {
                System.out.println("INVALID CHOICE");
            }
        }
        input.close();
    }
}