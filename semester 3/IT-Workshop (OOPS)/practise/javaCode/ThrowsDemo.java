class ThrowsDemo {
	
	void checkAge(int age) { //throws AgeLessException{  
		
		AgeLessException ale = new AgeLessException (age);
		
		if (age<18) throw ale;
	   }
	
	void method(int age, int number) throws ArithmeticException {
		
		int result = age/(age-number);
		System.out.println("Result is: "+result);
	}
	
	public static void main(String args[]){
		
		ThrowsDemo obj = new ThrowsDemo();
		int age = 3;
				
		try {
			obj.checkAge(age); //throw case
			obj.method(age, 3); //throws case
		}
		catch (AgeLessException e) {
			System.out.println("Age less exception..."+e.getDetails());  
		}
		catch (Exception e) {
			System.out.println("Arithmatic exception...");  
		}
		
		System.out.println("End Of Program");  
	   }  
	}
