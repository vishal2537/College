// package temp---;

// public class test {
//     public static void main(String[] args)
//     {
//         // System.out.println("2");
//         int z=1;
//         new test().increse(z);
//         System.out.print(z);        

//     } 

//     public static void main(String args)
//     {
//         System.out.println("2");
//     } 
//     void increse(int z)
//     {
//         System.out.print(z++);
//     }

// }

// class base {

//     static int i;
//     static {
//         System.out.println(1);
//         i = 100;

//     }
// }

// public class test{
//     static{
//         System.out.println(2);
//     }

//     public static void main(String [] args)
//     {
//         System.out.println(3);
//         System.out.println(base.i);
//     }
// }

// class b{
//     static int i;
// }

// public class test
// {
//     public static void main(String [] args)
//     {
//         System.out.println(b.i);

//     }

// }

// class base{
//     void m(Object obj)
//     {
//         System.out.println(1);
    
//     }
// }

// class child extends base{
//     void m()
//     {
//         System.out.println(2);
//     }

// }

// public class test{
//     public static void main(String []args)
//     {
//         base b1 =new child();
//         b1.m();
//     }

// }

public class test {
    int i=21;
    int j=9;

    public static void main(String[] args)
    {
        m();
    }

    public static void m()
    {
        int k = i+ j;
        System.out.println(k);
    }


}

