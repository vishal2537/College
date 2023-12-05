
// multitasking and multithreading 

// multitasking refer to a computer ability to perform multiple job concurrently
//  more than one program are running concurrently
// a thread is single sequence of execution within a program 
// multithreading refers to  multiple threads control within a single program 
//  each program can run multiple threads of control within it

// threads and process
// -- process : an executing instance of a program is called a process.
// -- thread : a thread is a subset of process.
// thread share the address space of the process that created it; process have their own address space.

// what are the threads good for?
//  to maintain responsiveness of an application during  a long running task 
//  to enable cancellation of separable tasks.
// some problem are intrinsically parallel.
// to monitor status of some resources
// some apis and system demand it : swing

// application thread --
// when we execute an application :
// the jvm creates a thread object whose task is define by yhe main() method
// it start the thread

// multiple thread in an application
//  each thread has its private run-time stack 
// if two threads execute the same method each will have its own copy of the local variable the method uses
//  however all threads see the same dynamic memory (heap)
// two different threads can act on the same object and same static fields concurrently.

// creating threads
// two way to create thread
// 1- > sub classing the thread class and instantiating a new object of that class
// 2-> implementing the runnable interface
// in both case the run() method should be implemented

public class threading {
    public static void main(String[] args) {
        Myclass myclass = new Myclass();
        myclass.start();

        Myclass myclass1 = new Myclass();
        myclass1.start();

    }
}

class Myclass extends Thread {
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getId() + " value : " + i);
        }
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }

}
