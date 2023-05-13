//package InheritancePolimorphism;

class Bike
{
	 final int speedlimit = 90;//final variable  
	 
	 double speed = 50;

	 void speed()
	 {
		 System.out.println("Speed is "+speed);
	 }
	 void run()
	 {
		 //speedlimit=400; //changing values is NOT allowed
	 }
	 
	 final void runTest()
	 {
		 System.out.println("Speed limit is fixed at "+speedlimit);
	 }
}
	  
class TurboBike extends Bike
{
	/*void runTest() //cannot override the final method runTest()
	{
		System.out.println("Runs at a duble spped " +speedlimit*2);
	}*/
	
}

final class SuzukiBike extends Bike
{
	
}


/*class SuzukiNewBike extends SuzukiBike //cannot entend a final class
{
	
}*/

public class FinalDemo {

	public FinalDemo() 
	{
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) 
	{
		Bike b = new Bike();
		b.speed();

	}

}
