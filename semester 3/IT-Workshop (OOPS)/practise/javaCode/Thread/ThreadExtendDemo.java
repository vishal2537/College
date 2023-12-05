//package Thread;

class Hi extends Thread
{
	Hi()
	{
		//System.out.println("Hi thread constructor");
		
	}
	public void run()
	{
		try {
			for(int n = 5; n > 0; n--) {
				System.out.println("Hi "+n);
				System.out.println("Fun..");
				Thread.sleep(1000);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
	}
}
public class ThreadExtendDemo {

	public static void main(String[] args) {
		
		Hi obj1 = new Hi(); //thread creation
		obj1.start(); //thread initiation
		
		try {
			for(int n = 5; n > 0; n--) {
				System.out.println("Main "+n);
				Thread.sleep(5000);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("Exiting main thread...");
		
	}

}
