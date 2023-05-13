import javax.swing.*;

public class SampleGUIExtendJFrame extends JFrame
{
	SampleGUIExtendJFrame(String name)
	{
		super(name);
		setLocation(200, 300);
		
		JButton b=new JButton("click");  
		b.setBounds(0,0,100, 40);
				          
		add(b);//adding button on frame  
				
		setSize(400,500);  
		setLayout(null);  
		setVisible(true);
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) 
	{
		new SampleGUIExtendJFrame("Welcome");
	}

}
