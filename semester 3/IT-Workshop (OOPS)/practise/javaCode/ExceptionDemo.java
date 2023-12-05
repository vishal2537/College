import java.util.Scanner;
import java.util.InputMismatchException;

public class ExceptionDemo {
	
	public static void f() {
		
	}
	public static void main(String[] args) {
	
		Scanner scanner = new Scanner( System.in ); // scanner for input
		boolean continueLoop = true;
		
		do {
			try {
				
				System.out.print( "Please enter an integer numerator: " );
				int numerator = scanner.nextInt();
				System.out.print( "Please enter an integer denominator: " );
				int denominator = scanner.nextInt();
				int result = numerator / denominator ;
				System.out.printf("\nResult: %d / %d = %d\n", numerator, denominator, result );
				
				continueLoop = false;
			}
			catch ( ArithmeticException arithmeticException )
			{
				System.err.printf( "\nException: %s\n", arithmeticException );
				System.out.println("Zero is an invalid denominator. Please try again.\n" );
			}
			catch ( InputMismatchException inputMismatchException )
			{
				System.err.printf( "\nException: %s\n",
						inputMismatchException );
				scanner.nextLine(); // discard input so user can try again
				System.out.println("You must enter integers. Please try again.\n" );
			} 
			catch ( Exception  e )
			{
			
				System.err.println( "\nException: "); e.printStackTrace();
				scanner.nextLine(); // discard input so user can try again
				System.out.println("You must enter integers. Please try again.\n" );
			}

			finally {
				System.out.println("Finally, we are here..");
			}
			
		} while (continueLoop);
		
		scanner.close();
	}

}
