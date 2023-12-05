import java.util.Scanner;

public class Q2 {
    static int check_palindrome(int n) {
        int num = n;
        int reverse = 0;
        while (num != 0) {
            int remainder = num % 10;
            reverse = reverse * 10 + remainder;
            num = num / 10;
        }
        if (reverse == n) {
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("ENTER SIZE OF ARRAY : ");

        int n = input.nextInt();

        int[] array;
        array = new int[n];

        System.out.println("ENTER THE ELEMENTS : ");
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }

        for (int i = 0; i < array.length; i++) {
            while (check_palindrome(array[i]) == 0) {
                array[i] += 1;
            }
        }
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
        input.close();
    }
}
