/*
 * classes in java can be extended,
 * creating new classes which retain 
 * characteristics of the base class
 */
class polygon {
    protected int height;
    protected int width;

    public void set_values(int a, int b) {
        height = a;
        width = b;
    }
}

class rectangle extends polygon {
    public double area() {
        return (height * width);
    }
}

class triangle extends polygon {
    public double area() {
        return ((height * width) / 2);
    }
}

public class inheritance {
    public static void main(String[] args) {
        rectangle rec = new rectangle();
        triangle tri = new triangle();

        rec.set_values(10, 10);
        tri.set_values(10, 20);
        System.out.println(rec.area());
        System.out.println(tri.area());
    }
}
