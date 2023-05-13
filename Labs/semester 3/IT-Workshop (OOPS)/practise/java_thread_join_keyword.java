
public class java_thread_join_keyword {
    private static int count = 0;

    public static synchronized void incount() {
        count++;
    }

    public static void main(String[] args) {
        Thread t1 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 10000; i++) {
                    // count++;
                    incount();
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 10000; i++) {
                    // count++;
                    incount();
                }
            }
        });

        t1.start();
        t2.start();
        try {
            // java thread join method can be used to pause the current thread execution
            // until the
            // specific thread is dead
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            // TODO: handle exception
            e.printStackTrace();
        }
        System.out.println("value : " + count);
    }

}
