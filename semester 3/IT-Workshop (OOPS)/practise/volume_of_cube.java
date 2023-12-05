class cube {
    int length;
    int breadth;
    int height;

    // getter and setter -->encapsulation
    public int getcubevolume() {
        return (length * breadth * height);
    }

    // constructor --> never return any value and name is same as class
    // constructor are generally use to initialise values in class

    // default constructor
    cube() {
        // System.out.println(" we are in constructor ");
        length = 10;
        breadth = 20;
        height = 10;
    }

    // constuctor overloading
    cube(int l, int b, int h) {
        // System.out.println(" we are in constructor overloading");
        length = l;
        breadth = b;
        height = h;
    }

}

public class volume_of_cube {
    public static void main(String[] args) {
        cube cube1 = new cube(); // object 

        System.out.println(cube1.getcubevolume());

        cube cube2 = new cube(20, 20, 20);
        System.out.println(cube2.getcubevolume());

    }
}
