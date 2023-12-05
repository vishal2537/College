// package gui;
import java.util.concurrent.Flow;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class second {
    public static void main(String[] args) {
        Abc obj = new Abc();
        // obj.setVisible(true);
        // obj.setSize(400, 400);
    }
}

class Abc extends JFrame { // card layout
    public Abc() {
        JLabel l = new JLabel("hello world");
        JLabel ll = new JLabel("world");

        add(l);
        add(ll);

        setLayout(new FlowLayout());
        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
