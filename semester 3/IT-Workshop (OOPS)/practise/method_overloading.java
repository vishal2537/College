public class method_overloading {
    public static void main(String[] args) {
        System.out.println(add(1, 2));
        System.out.println(add(4, 4));
    }

    public static int add(int a, int b) {
        return (a + b);
    }

    public static double add(Double a, Double b) {
        return (a + b);
    }

    public static String add(String a, String b) {
        return (a + b);
    }

}
