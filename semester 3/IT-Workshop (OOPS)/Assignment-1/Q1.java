import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter an integer: ");
        int a = input.nextInt();
        System.out.print("Enter an integer: ");
        int b = input.nextInt();
        int c = a + b;
        int d = a - b;
        System.out.println("sum : " + c);
        System.out.println("difference : " + d);

        System.out
                .println("The addition of " + a + " and " + b + " is " + c + " and when " + a + " is subtracted from "
                        + b + ", result is " + d);

        input.close();
    }
}
