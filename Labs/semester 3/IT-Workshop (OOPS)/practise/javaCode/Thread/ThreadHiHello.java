class NewHi extends Thread
{
	public void run()
	{
		try {
			for(int n = 10; n > 0; n--) {
				System.out.println("Hi "+n);
				Thread.sleep(500);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
	}
}
class NewHello extends Thread
{
	public void run()
	{
		try {
			for(int n = 10; n > 0; n--) {
				System.out.println("Hello "+n);
				Thread.sleep(500);
			}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
	}
}

public class ThreadHiHello {

	public static void main(String[] args) {
		
		NewHi obj1 = new NewHi();
		NewHello obj2 = new NewHello();
		NewHi obj3 = new NewHi();
		NewHi obj4 = new NewHi();
		NewHello obj5 = new NewHello();
		
		obj1.start(); obj2.start();
		obj3.start(); obj4.start();
		obj5.start(); 

	}

}
