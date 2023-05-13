import java.util.Scanner; // program uses class Scanner to obtain input

public class Addition
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
		sum = number1 + number2;
		System.out.println("Sum is: "+sum);
		System.out.printf( "Sum is %d\n", sum ); // display sum using formatted output
		System.out.printf("Number1 is %d \n Number 2 is %d \n and Sum is %d", number1, number2, sum);
		System.out.printf("Number1 is %d %n Number 2 is %d %n and Sum is %d", number1, number2, sum);
		
	} // end method main
} // end class Addition

