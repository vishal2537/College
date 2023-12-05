class AgeLessException extends RuntimeException {
	
	int age; 
	
	AgeLessException (int age) {
		this.age =age;
		System.out.println("NOT Eligible for voting");
	}
	
	AgeLessException (String str, int age) {
		super(str);
		System.out.println("NOT Eligible for voting");
		this.age =age;
	}
	
	String getDetails() {
		
		return "Age value is "+age;
	}
}

class ThrowDemo {
	/*
	void checkAge(int age){  
		if(age<18)  
		   throw new AgeLessException("Lesser age exception", age);  
		else  
		   System.out.println("All good");  
	   }
	*/
	public static void main(String args[]){
		
		ThrowDemo obj = new ThrowDemo();
		int age = 3;
		
		if(age<18)  
			   throw new AgeLessException("Lesser age exception", age); 
		
		System.out.println("End Of Program");  
	   }  
	}