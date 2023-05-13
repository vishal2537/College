//package Thread;

class Hello implements Runnable
{
	Thread t;
	
	Hello()
	{
		t=new Thread(this, "Thread Hello");
		t.start();
	}
	public void run()
	{
		try {
			for(int n = 10; n > 0; n--) {
				System.out.println("Hello "+n);
				Thread.sleep(1000);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
	}
}
public class ThreadDemoRunnable {

	public static void main(String[] args) {
		
			
		new Hello(); //creating thread and initiating through constructor
		
		try {
			for(int n = 10; n > 0; n--) {
				System.out.println("Main "+n);
				Thread.sleep(500);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("Exiting main thread...");
	}

}
