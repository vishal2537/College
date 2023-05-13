import java.util.*;
import java.util.Comparator;
import java.util.Scanner;
import java.util.regex.*;

class user {
    protected String firstname;
    protected String lastname;
    protected String dateOfBirth;
    protected String PAN;
    protected int addressPIN;
    protected String emailId;

    user() {
    }

    public user(String firstname, String lastname, String dateOfbirth, String PAN, int addressPIN, String emailId) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.dateOfBirth = dateOfbirth;
        this.PAN = PAN;
        this.addressPIN = addressPIN;
        this.emailId = emailId;
    }

    public void display() {
        System.out.println("\t\tNAME : " + firstname + " " + lastname);
        System.out.println("\t\tDATEOFBIRTH : " + dateOfBirth);
        System.out.println("\t\tPAN : " + PAN);
        System.out.println("\t\tADDRESSPIN : " + addressPIN);
        System.out.println("\t\tEMAIL-ID : " + emailId);
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public int getAddressPIN() {
        return addressPIN;
    }

    public String getEmailId() {
        return emailId;
    }

    public String getPAN() {
        return PAN;
    }

    public static String validatePAN(String PAN) {
        Scanner input = new Scanner(System.in);
        if (!PAN.matches("^[A-Z0-9]*$")) {
            System.out.println("Invalid PAN.Enter again :");
            return validatePAN(input.nextLine());
        }
        return PAN;
    }

    public static String validateFirstName(String firstName) {
        Scanner input = new Scanner(System.in);
        if (!firstName.matches("^[A-Za-z]*$")) {
            System.out.println("Invalid Name.Enter again :");
            return validateFirstName(input.nextLine());
        }
        return firstName;
    }

    public static String validateLastName(String lastName) {
        Scanner input = new Scanner(System.in);
        if (!lastName.matches("^[A-Za-z]*$")) {
            System.out.println("Invalid Name.Enter again :");
            return validateLastName(input.nextLine());
        }
        return lastName;
    }

    public static int validatePIN(int PIN) {
        Scanner input = new Scanner(System.in);
        if (String.valueOf(PIN).length() != 6) {
            System.out.println("Invalid PIN.Enter again :");
            int newPIN = input.nextInt();
            input.nextLine();
            return validatePIN(newPIN);
        }
        return PIN;
    }

    public static String validateDOB(String dateofbirth) {
        Scanner input = new Scanner(System.in);
        if (dateofbirth.length() != 10
                || !dateofbirth.matches("^(0[1-9]|1[0-2])/(0[1-9]|1\\d|2\\d|3[01])/(19|20)\\d{2}$")) {
            System.out.println("Invalid DOB.Enter again :");
            return validateDOB(input.nextLine());
        }
        return dateofbirth;
    }

    public int birthyear() {
        return Integer.parseInt(dateOfBirth.substring(6, 10));
    }

}

class student extends user {
    private int rollNumber;

    student() {
    }

    public student(String firstname, String lastname, String dateOfbirth, String PAN, int addressPIN, String emailId,
            int rollNumber) {
        super(firstname, lastname, dateOfbirth, PAN, addressPIN, emailId);
        this.rollNumber = rollNumber;
    }

    public void display() {
        super.display();
        System.out.println("\t\tROLL NUMBER : " + rollNumber);
    }

    public int getRollNumber() {
        return rollNumber;
    }
}

class faculty extends user {
    private int employeeID;

    public faculty() {
    }

    public faculty(String firstname, String lastname, String dateOfbirth, String PAN, int addressPIN, String emailId,
            int employeeID) {
        super(firstname, lastname, dateOfbirth, PAN, addressPIN, emailId);
        this.employeeID = employeeID;
    }

    public void display() {
        super.display();
        System.out.println("\t\tEMPLOYEEID : " + employeeID);
    }

    public int getEmployeeID() {
        return employeeID;
    }

}

class staff extends user {
    private int staffID;

    public staff() {
    }

    staff(String firstname, String lastname, String dateOfbirth, String PAN, int addressPIN, String emailId,
            int staffID) {
        super(firstname, lastname, dateOfbirth, PAN, addressPIN, emailId);
        this.staffID = staffID;
    }

    public void display() {
        super.display();
        System.out.println("\t\tSTAFFID : " + staffID);
    }

    public int getStaffID() {
        return staffID;
    }
}

class BirthYearComparator implements Comparator<user> {
    public int compare(user u1, user u2) {
        return u1.birthyear() - u2.birthyear();
    }
}

class RollNoComparator implements Comparator<student> {
    public int compare(student u1, student u2) {
        return u1.getRollNumber() - u2.getRollNumber();
    }
}

class EmployeeIDComparator implements Comparator<faculty> {
    public int compare(faculty u1, faculty u2) {
        return u1.getEmployeeID() - u2.getEmployeeID();
    }
}

class StaffIDComparator implements Comparator<staff> {
    public int compare(staff u1, staff u2) {
        return u1.getStaffID() - u2.getStaffID();
    }
}

public class assign_8 {

    public static boolean ValidMail(String email) {
        String regex = "^(.+)@(.+)$";
        Pattern p = Pattern.compile(regex);
        if (email == null) {
            return false;
        }
        Matcher m = p.matcher(email);
        return m.matches();
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<user> users = new ArrayList<user>();
        ArrayList<student> students = new ArrayList<student>();
        ArrayList<faculty> faculties = new ArrayList<faculty>();
        ArrayList<staff> staffs = new ArrayList<staff>();

        while (true) {
            System.out.println("\t\t1.input()\n\t\t2.output()");
            int ch = input.nextInt();

            if (ch == 1) {
                System.out.println("\t\t1.student()\n\t\t2.faculty()\n\t\t3.staff()");

                int ch1 = input.nextInt();
                input.nextLine();
                System.out.println("ENTER FIRST NAME : ");
                String firstname = input.nextLine();
                firstname = user.validateFirstName(firstname);

                System.out.println("ENTER LAST NAME : ");
                String lastname = input.nextLine();
                lastname = user.validateLastName(lastname);

                System.out.println("ENTER DATEOFBIRTH(DD/MM/YYYY) : ");
                String dateofbirth = input.nextLine();
                dateofbirth = user.validateDOB(dateofbirth);
                System.out.println(dateofbirth);

                System.out.println("ENTER PAN : ");
                String PAN = input.nextLine();
                PAN = user.validatePAN(PAN);

                System.out.println("ENTER ADDRESS PINCODE : ");
                int addressPIN = input.nextInt();
                addressPIN = user.validatePIN(addressPIN);

                input.nextLine();
                System.out.println("ENTER EMAILID : ");
                String emailId = input.next();
                while (!ValidMail(emailId)) {
                    System.out.println("!!INVALID AGAIN ENTER EMAILID : ");
                    emailId = input.nextLine();
                }

                if (ch1 == 1) {
                    System.out.println("ENTER ROLL NUMBER : ");
                    int rollNumber = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int j = 0; j < students.size(); j++) {
                            if (students.get(j) != null && students.get(j).getRollNumber() == rollNumber) {
                                System.out.println("ROLL NUMBER ALREADY EXIST !!");
                                System.out.println("ENTER ROLL NUMBER AGAIN :");
                                rollNumber = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }
                    student obj = new student(firstname, lastname, dateofbirth, PAN, addressPIN, emailId, rollNumber);
                    students.add(obj);
                    users.add(obj);

                } else if (ch1 == 2) {
                    System.out.println("ENTER EMPLOYEEID : ");
                    int employeeID = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int j = 0; j < faculties.size(); j++) {
                            if (faculties.get(j) != null && faculties.get(j).getEmployeeID() == employeeID) {
                                System.out.println("EMPLOYEEID ALREADY EXIST !!");
                                System.out.println("ENTER EMPLOYEEID AGAIN :");
                                employeeID = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    faculty obj = new faculty(firstname, lastname, dateofbirth, PAN, addressPIN, emailId, employeeID);
                    faculties.add(obj);
                    users.add(obj);

                } else if (ch1 == 2) {
                    System.out.println("ENTER STAFFID : ");
                    int staffID = input.nextInt();
                    while (true) {
                        int flag = 0;
                        for (int j = 0; j < staffs.size(); j++) {
                            if (staffs.get(j) != null && staffs.get(j).getStaffID() == staffID) {
                                System.out.println("STAFFID ALREADY EXIST !!");
                                System.out.println("ENTER STAFFID AGAIN :");
                                staffID = input.nextInt();
                                flag = 1;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }

                    staff obj = new staff(firstname, lastname, dateofbirth, PAN, addressPIN, emailId, staffID);
                    staffs.add(obj);
                    users.add(obj);

                }
            } else if (ch == 2) {
                System.out.println(
                        "\t\t1. BIRTHYEAR \n\t\t2. ROLLNUMBER :  \n\t\t3.EMPLOYEEID : \n\t\t4.STAFFID : ");
                int x = input.nextInt();
                if (x == 1) {
                    Collections.sort(users, new BirthYearComparator());

                    for (user u : users) {
                        u.display();
                        System.out.println();
                    }
                } else if (x == 2) {
                    Collections.sort(students, new RollNoComparator());
                    for (user u : students) {
                        u.display();
                        System.out.println();
                    }
                } else if (x == 3) {
                    Collections.sort(faculties, new EmployeeIDComparator());
                    for (user u : faculties) {
                        u.display();
                        System.out.println();
                    }
                } else {
                    Collections.sort(staffs, new StaffIDComparator());
                    for (user u : staffs) {
                        u.display();
                        System.out.println();
                    }
                }

            // } else if (ch == 6) {
            //     for (faculty user1 : faculties) {
            //         System.out.println(user1.getDateOfBirth());
            //     }
            // }
            }

        }
        // input.close();
    }
}