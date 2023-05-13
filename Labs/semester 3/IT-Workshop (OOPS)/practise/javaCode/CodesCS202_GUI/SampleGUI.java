import javax.swing.*;
import java.awt.*;


public class SampleGUI 
{
	public static void main(String args[])
	{
		JFrame f = new JFrame("Welcome");//creating instance of JFrame  
				
		JButton b=new JButton("Hi Button");//creating instance of JButton 
		
		b.setBounds(130,100,100, 40);//x axis, y axis, width, height  
		//b.setEnabled(false);  
		//b.setForeground(Color.green);
		b.setBackground(Color.green);
		f.add(b); //adding button in JFrame  
		
		JTextField tf = new JTextField();
		tf.setBounds(130,170,200, 50);
		f.add(tf);
		
		JTextArea ta = new JTextArea();
		ta.setBounds(30,270,200, 100);
		f.add(ta);
		
		f.setSize(400,500);//400 width and 500 height  
		f.setLayout(null);//using no layout managers  
		f.setVisible(true);//making the frame visible
		f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}

}
