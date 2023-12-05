class Counter
{
	int count;
	
	synchronized void increment()
	//void increment()
	{
		count++;
	}
	
}

public class ThreadSyncDemo {

	public static void main(String[] args)
	{
		Counter obj = new Counter();
		
		Thread t1 = new Thread ( new Runnable ( ) {
			
			public void run()
			{
				for(int n = 0; n < 5000; n++) {
						obj.increment();
					}
				
			}
		});
		
		
		Thread t2 = new Thread ( new Runnable ( ) {
			
			public void run()
			{
				for(int n = 0; n < 5000; n++) {
						obj.increment();
					}
				
			}
		});
		
		t1.start();
		t2.start();

		try 
		{
			System.out.println("Waiting for threads to finish.");
			t1.join();
			t2.join();
		}
		
		catch (InterruptedException e) 
		{
			System.out.println("Main thread Interrupted");
		}
		
		System.out.println("Count value is: "+obj.count);
	}

}
