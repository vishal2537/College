import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class addition extends JFrame {
    JTextField t1;
    JTextField t2;
    JButton b;
    JLabel l;

    public addition() {
        t1 = new JTextField(20); // textbox
        t2 = new JTextField(20);
        b = new JButton("ok"); // button
        l = new JLabel("result");

        add(t1);
        add(t2);
        add(b);
        add(l);

        b.addActionListener(ae -> {
            int num1 = Integer.parseInt(t1.getText());
            int num2 = Integer.parseInt(t2.getText());
            int value = num1 + num2;
            l.setText(value + " ");
        });

        // ActionListener al = new ActionListener()
        // {
        // public void actionPerformed(ActionEvent ae) {
        // int num1 = Integer.parseInt(t1.getText());
        // int num2 = Integer.parseInt(t2.getText());

        // int value = num1 + num2;
        // l.setText(value + " ");
        // }
        // };

        // b.addActionListener(al);
        setLayout(new FlowLayout());
        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class third {
    public static void main(String[] args) {
        addition obj = new addition();
    }
}