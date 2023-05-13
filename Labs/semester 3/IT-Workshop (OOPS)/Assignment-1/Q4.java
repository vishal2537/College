import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int m = 1;

        for (int i = 1; i <= 5; i++) {
            System.out.println("Enter student " + i);

            System.out.println("Enter marks for first subject");
            int s1 = input.nextInt();
            while (m > 0) {
                if (s1 < 0 || s1 > 100) {
                    System.out.println("re-enter the marks ");
                    s1 = input.nextInt();
                } else {
                    break;
                }
            }

            System.out.println("Enter marks for second subject");
            int s2 = input.nextInt();
            while (m > 0) {
                if (s2 < 0 || s2 > 100) {
                    System.out.println("re-enter the marks ");
                    s2 = input.nextInt();
                } else {
                    break;
                }
            }

            System.out.println("Enter marks for third subject");
            int s3 = input.nextInt();
            while (m > 0) {
                if (s3 < 0 || s3 > 100) {
                    System.out.println("re-enter the marks ");
                    s3 = input.nextInt();
                } else {
                    break;
                }
            }

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
