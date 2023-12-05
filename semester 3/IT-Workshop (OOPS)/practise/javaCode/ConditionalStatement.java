import java.util.Scanner; // program uses class Scanner to obtain input

public class ConditionalStatement
{
 // main method begins execution of Java application
	public static void main( String[] args )
	{
		Scanner input = new Scanner( System.in );
		int number1; // first number to add
		int number2; // second number to add
		int sum; // sum of number1 and number2
		System.out.print( "Enter first integer: " ); // prompt
		number1 = input.nextInt();
		System.out.print( "Enter second integer: " ); // prompt
		number2 = input.nextInt();
		if (number1 > number2)
			System.out.println("First number is larger");
		else
			System.out.println("Second number is larger");
		
	} // end method main
} // end class ConditionalStatement

