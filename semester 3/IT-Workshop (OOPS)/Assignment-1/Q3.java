import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        for (int i = 1; i <= 5; i++) {
            System.out.println("Enter student " + i + ": ");

            System.out.println("Enter marks for first subject");
            int s1 = input.nextInt();

            System.out.println("Enter marks for second subject");
            int s2 = input.nextInt();

            System.out.println("Enter marks for third subject");
            int s3 = input.nextInt();

            int avg = (s1 + s2 + s3) / 3;

            if (avg > 60) {
                System.out.println("Good");
            } else if (avg < 60 && avg > 30) {
                System.out.println("Ok");
            } else {
                System.out.println("Poor");
            }

        }
        input.close();
    }
}
