public class try_catch_finally {

    public static int retint()
    {
        int a = 100;
        try{
            a = 100 / 0;
            // System.exit(1);
            return a;
        }
        catch(ArithmeticException e)
        {
            System.out.println("catch called");
            System.out.println(e);
            return a;
        } 
        finally
        {
            System.out.println("finally called");
            // return a;
        }

    }
    public static void main(String [] args)
    {
        System.out.println(retint());

        // try{
        //     // int a = 100 / 0;
        //     System.exit(1);
        // }
        // catch(ArithmeticException e)
        // {
        //     System.out.println("catch called");
        //     System.out.println(e);
        // } finally
        // {
        //     System.out.println("finally called");
        // }
    }
    
}




