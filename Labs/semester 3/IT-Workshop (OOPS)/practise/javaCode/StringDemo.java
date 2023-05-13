import java.util.*;

public class StringDemo 
{

	public StringDemo() 
	{
		
	}

	public static void main(String[] args) 
	{
		String str = new String( "hello" );

		int i = str.length();

		char ch = str.charAt(2);

		String subStr = str.substring(1, 4);

		String capStr = str.toUpperCase();
	
		char chNew = "iiitg".charAt(2);
		
		boolean c= str.toUpperCase().contains("EL");
		
		System.out.println("Final output: "+i+" "+ch+" "+subStr+" "+capStr+" "+chNew+ " "+c);
		
		String strNew ="Hi! I am fine!";
		
		StringTokenizer st = new StringTokenizer (strNew,"!");
		
		while(st.hasMoreTokens()) 
		{
			System.out.println(st.nextToken());
		}
		
		String [ ]tokens = strNew.split(" ");
		for (String token: tokens)
		{
			System.out.println(token);
		}
		
		Scanner scanner = new Scanner( System.in );

		System.out.println( "Please enter first name:" );
		String firstName = scanner.nextLine();

		//if ( firstName.matches( "[A-Z][a-zA-Z]*" ) )
		
		if ( firstName.matches( "[A-Z][a-z]*" ) )
		{
			System.out.println("It is a valid name" );
		}
		else
			System.out.println( "This is not a valid name" );

	}

}
