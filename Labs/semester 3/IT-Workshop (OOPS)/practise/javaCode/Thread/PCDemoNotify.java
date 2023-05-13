class Queue {
	int n;
	boolean valueSet = false;

	synchronized int get() {
		while (!valueSet)
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		System.out.println("Got: " + n);
		valueSet = false;
		notify();
		return n;
	}

	synchronized void put(int n) {
		while (valueSet)
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("InterruptedException caught");
			}

		this.n = n;
		valueSet = true;
		System.out.println("Put: " + n);
		notify();
	}
}

class NewProducer implements Runnable {
	Queue q;

	NewProducer(Queue q) {
		this.q = q;
		new Thread(this, "Producer").start();
	}

	public void run() {
		int i = 0;
		while (true) {
			try {
				Thread.sleep(500);
			} catch (Exception e) {
			}
			q.put(i++);
		}
	}
}

class NewConsumer implements Runnable {
	Queue q;

	NewConsumer(Queue q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}

	public void run() {
		while (true) {
			try {
				Thread.sleep(500);
			} catch (Exception e) {
			}
			q.get();
		}
	}
}

public class PCDemoNotify {

	public static void main(String[] args) {
		Queue q = new Queue();
		new NewProducer(q);
		new NewConsumer(q);

		try {
			Thread.sleep(1000);
		} catch (Exception e) {
		}

		System.out.println("Press Control-C or Terminate button to stop.");

	}

}
