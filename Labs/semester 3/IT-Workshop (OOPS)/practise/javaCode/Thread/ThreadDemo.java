//package Thread;

public class ThreadDemo {

	public static void main(String[] args) 
	{
		Thread t = Thread.currentThread();
		System.out.println("Current thread: " + t.getName());
		
		System.out.println("State is: "+t.getState());
		
		// change the name of the thread
		t.setName("My Thread");
		
		System.out.println("After name change: " + t.getName());
		
		try {
			for(int n = 5; n > 0; n--) {
				System.out.println(n);
				Thread.sleep(-7000);
				System.out.println("State is: "+t.getState());
				}
		} catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
		
		
		System.out.println(Thread.activeCount());
				
	}

}
