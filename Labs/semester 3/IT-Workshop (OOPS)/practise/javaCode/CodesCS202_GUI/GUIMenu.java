import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GUIMenu extends JFrame implements ActionListener
{
	JMenu menu;
	JMenuItem a1,a2, a3;
	JPanel jp1, jp2;
	JTextArea ta;
	JTextField tf;
	JLabel l;
	
	GUIMenu()
	{
		super("Demo Text Editor");
		
		menu = new JMenu("File");
		JMenuBar m1 = new JMenuBar();
		m1.setBorderPainted(true);
		a1 = new JMenuItem("New");
		a2 = new JMenuItem("Open");
		a3 = new JMenuItem("Save");
		menu.add(a1); menu.add(a2); menu.add(a3); m1.add(menu); setJMenuBar(m1);
		
		a1.addActionListener(this);
		a2.addActionListener(this);
		a3.addActionListener(this);
		
		ta = new JTextArea();
		ta.setSize(390,300);
		add(ta, BorderLayout.CENTER);
		
		l = new JLabel("You selected");
		l.setSize(150,20);
		l.setLocation(50, 310);
		add(l);
		
		tf = new JTextField();
		tf.setSize(150,20);
		tf.setLocation(190, 310);
		add(tf);
		
		setSize(400,400);
		setLocation(200,200);
		setLayout(null);
		setVisible(true);
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent ae)
	{
		tf.setText(ae.getActionCommand());
		
	}
	public static void main(String[] args) 
	{
		new GUIMenu();
	}
}