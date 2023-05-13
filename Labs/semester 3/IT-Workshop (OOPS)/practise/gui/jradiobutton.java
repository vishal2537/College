import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class jradiobutton {
    public static void main(String[] args) {
        radiodemo r = new radiodemo();

    }
}

class radiodemo extends JFrame {
    JTextField t1;
    JButton b;
    JRadioButton r1, r2;
    JLabel l;
    JCheckBox c1, c2;

    public radiodemo() {
        t1 = new JTextField(15);
        b = new JButton("ok");
        r1 = new JRadioButton("male");
        r2 = new JRadioButton("female");
        l = new JLabel("greeting");
        c1 = new JCheckBox("dancing");
        c2 = new JCheckBox("singing");

        ButtonGroup bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);

        add(t1);
        add(b);
        add(c1);
        add(c2);
        add(r1);
        add(r2);
        add(l);

        c1.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                System.out.println("dancer");
            }
        });

        b.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = t1.getText();
                if (r1.isSelected()) {
                    name = " mr. " + name;

                } else {
                    name = "ms. " + name;
                }
                if (c1.isSelected()) {
                    name = name + " dancer";
                }
                if (c2.isSelected()) {
                    name = name + " singer";
                }
                l.setText(name);
            }
        });

        setLayout(new FlowLayout());
        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
}