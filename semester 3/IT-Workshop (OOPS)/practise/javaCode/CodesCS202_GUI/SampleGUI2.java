import javax.swing.*;
import java.awt.*;

public class SampleGUI2 extends JFrame
{
	SampleGUI2(String name)
	{
		super(name);
		setLocation(200, 300);
		
		JLabel l1 = new JLabel("First name");
		l1.setBounds(20,20,90,30);
		add(l1);
		JTextField tf = new JTextField();
		tf.setBounds(120,20,200, 30);
		add(tf);
		
		JLabel l2 = new JLabel("Last name");
		l2.setBounds(20,70,90,30);
		add(l2);
		JTextField tf2 = new JTextField();
		tf2.setBounds(120,70,200, 30);
		add(tf2);
		
		JButton b1 = new JButton("Submit");
		//b1.setSize(50, 25);
		JButton b2 = new JButton("Close");
		//b2.setSize(50, 25);
		JButton b3 = new JButton("Hi");
		//b1.setSize(50, 25);
		JButton b4 = new JButton("Hello");
		
		/*JPanel p1 = new JPanel();
		p1.setBounds(70, 200, 200, 50);
		p1.add(b1); p1.add(b2);  
		add(p1);*/
		
		 JPanel p1 = new JPanel(new GridLayout(2,2));
		p1.setBounds(70, 200, 200, 50);
		p1.add(b1); p1.add(b2); p1.add(b3); p1.add(b4); 
		add(p1);
				
		setSize(400,500);  
		setLayout(null);  
		setVisible(true);
		
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) 
	{
		new SampleGUI2("Welcome");

	}

}
