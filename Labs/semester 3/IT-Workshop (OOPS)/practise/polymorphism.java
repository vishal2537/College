class bank {
    int getinterestrate() {
        return 0;
    }
}

class bank_abc extends bank {
    int getinterestrate() {
        return 5;
    }
}

class bank_def extends bank {
    int getinterestrate() {
        return 6;
    }
}

class bank_xyz extends bank {
    int getinterestrate() {
        return 10;
    }
}

public class polymorphism {
    public static void main(String[] args) {
        bank abc = new bank_abc();
        bank def = new bank_def();
        bank xyz = new bank_xyz();
        
    System.out.println(abc.getinterestrate());
    System.out.println(def.getinterestrate());
    System.out.println(xyz.getinterestrate()); 
    }
}

// ability of object to have differnt form 
