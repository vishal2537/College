//package InheritancePolymorphism;

interface Bank
{  
	double rateOfInterest();  
}  

class SBI implements Bank
{  
	
	public double rateOfInterest()
	{
		return 9.15;
	}  
}  

class PNB implements Bank
{  
	
	public double rateOfInterest()
	{
		return 9.7f;
	}
}  


public class InterfaceDemo 
{

	public InterfaceDemo() 
	{
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) 
	{
		Bank ac1 = new SBI();  
		System.out.println("ROI: "+ac1.rateOfInterest());
		
		SBI ac2 = new SBI();
		System.out.println("ROI: "+ac2.rateOfInterest());
	}

}
