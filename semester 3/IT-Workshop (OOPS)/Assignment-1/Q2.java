import java.util.Scanner;

public class Q2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of element : ");
        int n = input.nextInt();

        System.out.print("Enter number : ");
        int a = input.nextInt();
        int largest_number = a;
         for (int i = 1; i < n; i++) {
            int b = input.nextInt();
            if (largest_number < b) {
                largest_number = b;
           }
        }
        System.out.print("largest number: " + largest_number);
        // closing the scanner object
        input.close();
    }
}