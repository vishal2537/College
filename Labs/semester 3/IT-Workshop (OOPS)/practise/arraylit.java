import java.util.*;


public class arraylit {
    public static void main(String [] args)
    {
        ArrayList<Integer> mylist = new ArrayList<Integer>(5);
        mylist.add(5);
        mylist.add(5);
        mylist.add(5);
        mylist.add(5);
        mylist.add(5);
        mylist.add(5);
        mylist.add(5); 

        for(Integer x:mylist)
        {
            System.out.println(x);
        }

        System.out.println(mylist.size());
    }
}
