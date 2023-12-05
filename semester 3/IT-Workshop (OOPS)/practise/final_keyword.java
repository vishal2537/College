/*
A final class cannot be subclassed
a final method cannot be ovverriden by subclasses
a final varable can only be initialised once
*/

class hello
{
    public final int number;
    hello()
    {
        number=10;
    }

}


public class final_keyword {
    public static void main(String []args) 
    {
        // hello hel=new hello();
        // hel.number=10;
    }   
}
