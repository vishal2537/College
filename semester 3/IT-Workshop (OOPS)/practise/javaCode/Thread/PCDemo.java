class Q {
	int n;
	synchronized int get() 
	{
		System.out.println("Got: " + n);
		return n;
	}
	synchronized void put(int n) 
	{
		this.n = n;
		System.out.println("Put: " + n);
	}
}

class Producer implements Runnable 
{
	Q q;
	Producer(Q q) {
		this.q = q;
		new Thread(this, "Producer").start();
	}
	
	public void run() {
		int i = 0;
		while(true) {
			try { Thread.sleep(500); } catch (Exception e) {}
			q.put(i++);
		}
	}
}

class Consumer implements Runnable {
	Q q;
	Consumer(Q q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	public void run() {
		while(true) {
			try { Thread.sleep(500); } catch (Exception e) {}
			q.get();
		}
	}
}




public class PCDemo {

	public static void main(String[] args) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		
		try { Thread.sleep(1000); } catch (Exception e) {}
		
		System.out.println("Press Control-C or Terminate button to stop.");

	}

}
