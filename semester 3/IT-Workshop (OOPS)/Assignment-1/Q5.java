import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number");

        int num = input.nextInt(), sum = 0;
        input.close();
        while (num != 0) {
            int x = num % 10;
            sum += x;
            num = num / 10;
        }
        System.out.println("The Sum of digit is : " + sum);
    }
}
