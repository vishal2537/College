package array;

import java.util.Arrays;

public class ArraysExample
{
	public static void main( String[] args )
	{
		double[] doubleArray = { 8.4, 9.3, 0.2, 7.9, 3.4 };

		Arrays.sort(doubleArray);

		System.out.printf( "\ndoubleArray: " );
		
		for( double value : doubleArray )
		System.out.printf( "%.1f ", value );

		int[] filledIntArray = new int[ 10 ];

		Arrays.fill(filledIntArray, 7);
		
		displayArray( filledIntArray, "filledIntArray" );
		
		int[] intArray = { 1, 2, 3, 4, 5, 6 };
		int[] intArrayCopy = new int[ intArray.length ];

		System.arraycopy(intArray, 0, intArrayCopy, 0, intArray.length);
		
		displayArray( intArray, "intArray" );
		displayArray( intArrayCopy, "intArrayCopy" );

		boolean b = Arrays.equals(intArray, intArrayCopy);
		
		if (b) System.out.println("Arrays are same");

		int location = Arrays.binarySearch(doubleArray, 5);
		
		System.out.println("5 is found in location "+location);
		
		Arrays.fill(intArray, 9);
		for(int ele:intArray)
		System.out.print(ele+" ");
		System.out.println();
		
		Arrays.fill(intArray, 2, 4, 5);
		for(int ele:intArray)
		System.out.print(ele+" ");
		System.out.println();
		
		int loc = Arrays.binarySearch(intArray, 5);
		System.out.println("5 IS FOUND IN LOCATION "+loc);
		
		String [] str1 = new String[5];
		
		String [] str2 = {"man", "sun", "tue"};
		
		Arrays.fill(str1, "hi");
		for(String ele:str1)
			System.out.print(ele+" ");
		System.out.println();
			
		
	}

	public static void displayArray( int[] array, String description )
	{
		System.out.printf( "\n%s: ", description );
		for ( int value : array )
		System.out.printf( "%d ", value );
	}
}
