
public class WrapperDemo {

	
	public static void main(String[] args) {
		
		int testInt = 20;  
		
		
		//Integer myIntObj = new Integer(5); //old version

		Integer myIntObj = 7; //autoboxing, now compiler will write Integer.valueOf(a) internally  
		
		Integer myIntObjNew = testInt; //autoboxing
		
		Integer myAnotherIntObj = Integer.valueOf(testInt);//converting int into Integer object explicitly
		
		System.out.println("int to Integer object: "+ testInt +" "+myIntObj+ " "+ myIntObjNew+ " "+myAnotherIntObj);
		
		int myPrimInt = myIntObj.intValue();

		int myPrimIntNew = myIntObj;
		
		System.out.println(" Integer object to integer: "+ myPrimInt + " "+myPrimIntNew + " "+myIntObj);
		
		Character myCharObj = 'x';
		
		char myChar = myCharObj;

		System.out.println( myCharObj + " "+ myChar+" "+myCharObj);


	}

}
