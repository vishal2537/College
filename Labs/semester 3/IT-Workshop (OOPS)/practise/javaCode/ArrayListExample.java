//package array;

import java.util.ArrayList;

public class ArrayListExample {

	public ArrayListExample() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		
		ArrayList< String > items = new ArrayList< String >();
		items.add("red");
		items.add(0, "yellow");
		items.add("green");
		
		
		for ( int i = 0; i < items.size(); i++ )
			System.out.print( items.get( i ) );
			
		ArrayList<String> items2 = new ArrayList<String>();
		
		items2.addAll(items);
		
		System.out.println();
		for ( int i = 0; i < items2.size(); i++ )
			System.out.printf( " %s", items2.get( i ) );
		
		items.remove(1);
		
		System.out.println();
		for ( int i = 0; i < items.size(); i++ )
			System.out.print( items.get( i ) );
		
		
		/* Wrapper class */
		System.out.println("Integer arraylist");
		
		ArrayList<Integer> intItems = new ArrayList<Integer>();
		
		intItems.add(2); intItems.add(3); intItems.add(4); intItems.add(5);
		intItems.remove(intItems.get(0));
		//intItems.remove(2);
		
		System.out.println();
		for ( int i = 0; i < intItems.size(); i++ )
			System.out.print(intItems.get( i ) );
				
	}

}
