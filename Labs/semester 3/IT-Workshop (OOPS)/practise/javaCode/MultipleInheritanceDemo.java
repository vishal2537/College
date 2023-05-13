//package InheritancePolimorphism;

interface Printable{  

void print();  
}  

interface Showable{  

void print();

// private void f() {} //testing: private method is allowed
int g = 5; //testing: field has to be initialized but automatically becomes static as no object is created for this class
}  

public class MultipleInheritanceDemo implements Printable, Showable
{
	
	public MultipleInheritanceDemo() 
	{
		// TODO Auto-generated constructor stub
	}
	
	public void print()
	{
		//g++;
		System.out.println("Hello! I am inside demo class "+g);
	}

	public static void main(String[] args) 
	{
		MultipleInheritanceDemo mid = new MultipleInheritanceDemo();
		mid.print();
		
		//System.out.println(MultipleInheritanceDemo.g);
		//System.out.println(mid.g); //testing: OK but provides a warning

	}

}
