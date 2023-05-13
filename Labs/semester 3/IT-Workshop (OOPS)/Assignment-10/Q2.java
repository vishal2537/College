import java.io.*;
import java.util.*;

class Student extends Object implements Serializable {

    String firstName;
    String lastName;
    int rollNumber;
    float cpi;
    int age;

    public Student(String firstName, String lastName, int rollNumber, float cpi, int age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.rollNumber = rollNumber;
        this.cpi = cpi;
        this.age = age;
    }

    public String toString() {
        return "Student [firstName=" + firstName + ", lastName=" + lastName + ", rollNumber=" + rollNumber + ", cpi="
                + cpi + ", age=" + age + "]";
    }
}


public class Q2 {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();
        for (int i = 9; i < 21; i++) {
            students.add(new Student(Integer.toString(i), Integer.toString(i), i, i, i));
        }

        writeSerialization(students, "students.ser");
        ArrayList<Object> newStudents = readSerialization("students.ser");
        ArrayList<Student> studentArray = new ArrayList<>();
        for (Object object : newStudents) {
            studentArray.add((Student) object);
        }
        System.out.println("Name with M");
        nameWithM(studentArray);
        System.out.println("Age less than 18");
        ageLessThan18(studentArray);

    }

    public static void writeSerialization(Object object, String fileName) {
        try {
            FileOutputStream file = new FileOutputStream(fileName);
            ObjectOutputStream out = new ObjectOutputStream(file);
            out.writeObject(object);
            out.close();
            file.close();
            System.out.println("Object has been serialized");
        } catch (IOException ex) {
            System.out.println("IOException is caught in writing");
        }
    }

    public static ArrayList<Object> readSerialization(String fileName) {
        ArrayList<Object> objects = new ArrayList<>();
        try {
            FileInputStream file = new FileInputStream(fileName);
            ObjectInputStream in = new ObjectInputStream(file);
            objects = (ArrayList<Object>) in.readObject();
            in.close();
            file.close();
        } catch (IOException ex) {
            System.out.println("IOException is caught in reading");
        } catch (ClassNotFoundException ex) {
            System.out.println("ClassNotFoundException is caught");
        }
        return objects;
    }

    public static void nameWithM(ArrayList<Student> students) {
        for (Student student : students) {
            if (student.firstName.charAt(0) == 'M') {
                System.out.println(student);
            }
        }
    }

    public static void ageLessThan18(ArrayList<Student> students) {
        for (Student student : students) {
            if (student.age < 18) {
                System.out.println(student);
            }
        }
    }
}

