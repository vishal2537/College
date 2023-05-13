public class CommandLineDemo {

	public static void main(String[] args) {
		
		// check number of command-line arguments
		if ( args.length != 3)
		System.out.println("Error: Please re-enter the entire command, including \n an array size, initial value and increment." );
		
		
		
		else {
			// get array size from first command-line argument and create the array
			int arrayLength = Integer.parseInt( args[ 0 ] );
			
			int[] array = new int[ arrayLength ]; // create array
			
			// get initial value and increment from command-line arguments
			int initialValue = Integer.parseInt( args[ 1 ] );
			int increment = Integer.parseInt( args[ 2 ] );
		
			for ( int counter = 0; counter < array.length; counter++ )
			array[ counter ] = initialValue + increment * counter;
		
			System.out.println( "Index \t Value" );
		
			// display array index and value
			for ( int counter = 0; counter < array.length; counter++ )
				System.out.println( counter + "\t "+ array[ counter ] );
				
			} // end else
		} // end main
	} 
