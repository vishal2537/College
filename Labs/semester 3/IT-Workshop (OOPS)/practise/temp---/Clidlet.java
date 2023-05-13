// class car {

//     public void maxSpeed(int speed) {
//         System.out.println("Max speed is ” +speed+ “ mph");
//     }

// }

// class Ferrari extends car {

//     public void maxSpeed(float speed) {
//         System.out.println("Max speed is ” +speed+ “ mph");
//     }

//     public void msc() {
//     }

// }

// public class C {

//     public static void main(String[] args) {
//         car r = new car();
//         Ferrari f= new Ferrari();
//     }

// }

class Clidder {
    private final void flipper() {
        System.out.println("Clidder");
    }
}

public class Clidlet extends Clidder {
    public final void flipper() {
        System.out.println("Clidlet");
    }

    public static void main(String[] args) {
        new Clidlet().flipper();
    }
}