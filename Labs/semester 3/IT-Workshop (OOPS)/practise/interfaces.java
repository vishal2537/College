// class class extends
// interface class implement 
// interface interface extends
// interfaces are abstract by nature 

interface bank {
   int getinterestrate();
    
}

class bankabc implements bank{
    int getinterestrate() {
        return 5;
    }
}

public class interfaces {
    public static void main(String[] args) {

        bank bc = new bank();
    }
    
}
