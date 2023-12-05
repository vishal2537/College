import java.util.Scanner;

public class LoopSwitch
{
 	public static void main( String[] args )
	{
		Scanner input = new Scanner( System.in );
		int number; 
		
		for(int i=0; i<3; i++)
		{
			System.out.print( "Enter first integer: " ); 

			number = input.nextInt();
	
			switch(number)
			{
				case 0:
				System.out.println("You typed zero");
				break;
			
				case 1:
				System.out.println("You typed one");
				break;
			
				default:
				System.out.println("Neither zero nor one");
			}
		}
	} 
} 

