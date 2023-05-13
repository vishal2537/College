
// package gui;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class firtgui {
    public static void main(String[] args) {
        Abc obj = new Abc();
        // obj.setVisible(true);
        // obj.setSize(400, 400);
    }
}

class Abc extends JFrame {
    public Abc() {
        JLabel l = new JLabel("hello world");
        add(l);
        setVisible(true);
        setSize(400, 400);
    }
}
