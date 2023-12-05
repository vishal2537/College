import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class addition extends JFrame implements ActionListener {
    JTextField t1;
    JTextField t2;
    JButton b1, b2;
    JLabel l;

    public addition() {
        t1 = new JTextField(20); // textbox
        t2 = new JTextField(20);
        b1 = new JButton("add"); // button
        b2 = new JButton("subtraction"); // button

        l = new JLabel("result");

        add(t1);
        add(t2);
        add(b1);
        add(b2);
        add(l);

        b1.addActionListener(this); // actionlistener is an interface
        b2.addActionListener(this); // actionlistener is an interface

        setLayout(new FlowLayout());
        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    // public void actionPerformed(ActionEvent ae) {
    public void actionPerformed(ActionEvent ae) {
        int num1 = Integer.parseInt(t1.getText());
        int num2 = Integer.parseInt(t2.getText());
        int value = 0;
        if (ae.getSource() == b1) {
            value = num1 + num2;
            l.setText(value + " ");
        } else
            value = num1 - num2;
            l.setText(value + " ");
    }

}

public class subtaction {
    public static void main(String[] args) {
        addition obj = new addition();
    }
}