

abstract class bank {
    int getinterestrate()
    {
        return  0 ; 
    }
}

class bankabc extends bank{
    int getinterestrate()
    {
        return  5 ; 
    } 
}

public class abstract_method {
    public static void main(String[] args) {
        bank abc =new bankabc(); //reference type 
        System.out.println(abc.getinterestrate());
        
    }
    
}
