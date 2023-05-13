import java.util.Scanner;

public class NoExceptionDemo {
	public static void main(String[] args) {
	
		Scanner scanner = new Scanner( System.in ); // scanner for input
	
		System.out.print( "Please enter an integer numerator: " );
		int numerator = scanner.nextInt();
		System.out.print( "Please enter an integer denominator: " );
		int denominator = scanner.nextInt();
		int result = numerator / denominator ;
		System.out.printf("\nResult: %d / %d = %d\n", numerator, denominator, result );
		scanner.close();
	}

}
