package Server;

import java.net.*;
import java.io.*;
import java.util.*;

public class server {

    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();
        writeSerialization(students, "students.ser");
        while (true) {
            try {
                ServerSocket server = new ServerSocket(6666, 10);
                Socket connection = server.accept();
                DataInputStream input = new DataInputStream(connection.getInputStream());
                DataOutputStream output = new DataOutputStream(connection.getOutputStream());
                String code = input.readUTF();

                switch (code) {
                    case "0" -> {
                        students = readSerialization("students.ser");
                        String name = input.readUTF();
                        String roll = input.readUTF();
                        students.add(new Student(name, roll));
                        print(students);
                        writeSerialization(students, "students.ser");
                    }
                    case "1" -> {
                        students = readSerialization("students.ser");
                        String roll = input.readUTF();
                        for (Student student : students) {
                            if (student.RollNumber.equals(roll)) {
                                students.remove(student);
                                break;
                            }
                        }
                        print(students);
                        writeSerialization(students, "students.ser");

                    }
                    case "2" -> {
                        students = readSerialization("students.ser");
                        String name = input.readUTF();
                        String roll = input.readUTF();
                        for (Student student : students) {
                            if (student.RollNumber.equals(roll)) {
                                student.Name = name;
                                break;
                            }
                        }
                        print(students);
                        writeSerialization(students, "students.ser");

                    }
                    case "3" -> {
                        students = readSerialization("students.ser");
                        print(students);
                        String name = input.readUTF();
                        String roll = "null";
                        for (Student student : students) {
                            if (student.Name.equals(name)) {
                                roll = student.RollNumber;
                                break;
                            }
                        }
                        output.writeUTF(roll);

                        writeSerialization(students, "students.ser");
                    }
                    case "4" -> {
                        students = readSerialization("students.ser");
                        print(students);
                        String roll = input.readUTF();
                        String Name = "null";
                        for (Student student : students) {
                            if (student.RollNumber.equals(roll))
                                Name = student.Name;
                        }
                        output.writeUTF(Name);
                        writeSerialization(students, "students.ser");

                    }

                }

                input.close();
                connection.close();
                server.close();

            } catch (IOException IE) {

            }
        }

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

    @SuppressWarnings("unchecked")
    public static ArrayList<Student> readSerialization(String fileName) {

        ArrayList<Student> objects = new ArrayList<>();
        try {
            FileInputStream file = new FileInputStream(fileName);
            ObjectInputStream in = new ObjectInputStream(file);
            objects = (ArrayList<Student>) in.readObject();

            in.close();
            file.close();
        } catch (IOException ex) {
            System.out.println("IOException is caught in reading");
        } catch (ClassNotFoundException ex) {
            System.out.println("ClassNotFoundException is caught");
        }
        return objects;
    }

    public static void print(ArrayList<Student> students) {
        for (Student student : students) {
            System.out.println(student);
        }
    }

}

class Student implements Serializable {
    @Override
    public String toString() {
        return "Student [Name=" + Name + ", RollNumber=" + RollNumber + "]";
    }

    String Name;
    String RollNumber;

    public Student(String name, String rollNumber) {
        Name = name;
        RollNumber = rollNumber;
    }
}
