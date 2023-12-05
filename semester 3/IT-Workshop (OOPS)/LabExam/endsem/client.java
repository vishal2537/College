// package Client;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.net.*;
import java.io.*;

public class client {
    public static void main(String[] args) {
        new ApplicationGUI();
    }
}

class ApplicationGUI extends JFrame implements ActionListener {
    JButton Admin;
    JButton Student;

    ApplicationGUI() {
        super("App");

        Admin = new JButton("Admin");
        Student = new JButton("Student");

        Admin.addActionListener(this);
        Student.addActionListener(this);

        setLayout(new FlowLayout());
        add(Admin);
        add(Student);

        setSize(200, 200);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == Admin) {
            new AdminGUI();
        } else {
            new StudentGUI();
        }
    }
}

class AdminGUI extends JFrame implements ActionListener {
    JMenuBar menu;
    JMenu Admin;
    JMenuItem AddDetails;
    JMenuItem DeleteDetails;
    JMenuItem ModifyDetails;
    JLabel Name;
    JTextField name;
    JLabel RollNumber;
    JTextField roll;
    JButton Submit;

    AdminGUI() {
        super("Admin");

        menu = new JMenuBar();

        Admin = new JMenu("Operations");

        AddDetails = new JMenuItem("Add Details");
        DeleteDetails = new JMenuItem("Delete Details");
        ModifyDetails = new JMenuItem("Modify Details");

        AddDetails.addActionListener(this);
        DeleteDetails.addActionListener(this);
        ModifyDetails.addActionListener(this);

        Admin.add(AddDetails);
        Admin.add(DeleteDetails);s
        Admin.add(ModifyDetails);

        Name = new JLabel("Name :");
        name = new JTextField(20);
        RollNumber = new JLabel("Roll Number :");
        roll = new JTextField(20);
        Submit = new JButton("Submit");

        menu.add(Admin);

        add(menu);

        setLayout(new GridLayout(16, 16));

        setVisible(true);
        setSize(500, 500);

    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == AddDetails) {
            add(Name);
            add(name);
            add(RollNumber);
            add(roll);
            add(Submit);

            Submit.addActionListener(new ActionListener() {

                public void actionPerformed(ActionEvent e) {

                    String nameOfStudent = name.getText();
                    String rollNumber = roll.getText();
                    try {
                        Socket connection = new Socket("localhost", 6666);
                        DataInputStream input = new DataInputStream(connection.getInputStream());
                        DataOutputStream output = new DataOutputStream(connection.getOutputStream());
                        output.writeUTF("0");
                        output.writeUTF(nameOfStudent);
                        output.writeUTF(rollNumber);
                        input.close();
                        output.close();
                        connection.close();
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }

                }
            });

        }
        if (ae.getSource() == DeleteDetails) {

            add(RollNumber);
            add(roll);
            add(Submit);
            Submit.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    String rollNumber = roll.getText();
                    try {
                        Socket connection = new Socket("localhost", 6666);
                        DataInputStream input = new DataInputStream(connection.getInputStream());
                        DataOutputStream output = new DataOutputStream(connection.getOutputStream());
                        output.writeUTF("1");
                        output.writeUTF(rollNumber);
                        input.close();
                        output.close();
                        connection.close();
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }
                }
            });

        }
        if (ae.getSource() == ModifyDetails) {
            add(Name);
            add(name);
            add(RollNumber);
            add(roll);
            add(Submit);
            Submit.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    String nameOfStudent = name.getText();
                    String rollNumber = roll.getText();
                    try {
                        Socket connection = new Socket("localhost", 6666);
                        DataInputStream input = new DataInputStream(connection.getInputStream());
                        DataOutputStream output = new DataOutputStream(connection.getOutputStream());
                        output.writeUTF("2");
                        output.writeUTF(nameOfStudent);
                        output.writeUTF(rollNumber);
                        input.close();
                        output.close();
                        connection.close();

                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }
                }
            });
        }
    }
}

class StudentGUI extends JFrame implements ActionListener {
    JMenuBar menu;
    JMenu Student;
    JMenuItem ViewDetailsName;
    JMenuItem ViewDetailsRoll;
    JLabel Name;
    JTextField name;
    JLabel RollNumber;
    JTextField roll;
    JButton Submit;

    StudentGUI() {
        super("Student");

        menu = new JMenuBar();

        Student = new JMenu("Operations");

        ViewDetailsName = new JMenuItem("View Details By Name");
        ViewDetailsRoll = new JMenuItem("View Details By Roll Number");

        ViewDetailsName.addActionListener(this);
        ViewDetailsRoll.addActionListener(this);

        Student.add(ViewDetailsName);
        Student.add(ViewDetailsRoll);

        Name = new JLabel("Name :");
        name = new JTextField(20);
        RollNumber = new JLabel("Roll Number :");
        roll = new JTextField(20);
        Submit = new JButton("Submit");

        menu.add(Student);

        add(menu);
        add(Name);
        add(name);
        add(RollNumber);
        add(roll);

        setLayout(new GridLayout(16, 16));

        setVisible(true);
        setSize(500, 500);

    }

    public void actionPerformed(ActionEvent ae) {

        add(Submit);
        if (ae.getSource() == ViewDetailsName) {
            Submit.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    String nameOfStudent = name.getText();
                    try {
                        Socket connection = new Socket("localhost", 6666);
                        DataInputStream input = new DataInputStream(connection.getInputStream());
                        DataOutputStream output = new DataOutputStream(connection.getOutputStream());
                        output.writeUTF("3");
                        output.writeUTF(nameOfStudent);
                        roll.setText(input.readUTF());
                        input.close();
                        output.close();
                        connection.close();

                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }

                }
            });
        }
        if (ae.getSource() == ViewDetailsRoll) {
            Submit.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    String rollNU = roll.getText();
                    try {
                        Socket connection = new Socket("localhost", 6666);
                        DataInputStream input = new DataInputStream(connection.getInputStream());
                        DataOutputStream output = new DataOutputStream(connection.getOutputStream());
                        output.writeUTF("4");
                        output.writeUTF(rollNU);
                        name.setText(input.readUTF());
                        input.close();
                        output.close();
                        connection.close();

                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }

                }
            });

        }
    }

}