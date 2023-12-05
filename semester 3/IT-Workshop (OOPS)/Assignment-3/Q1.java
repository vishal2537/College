import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter N : ");
        int n = input.nextInt();
        input.close();
        int[] a;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        int i = 0, size = n;
        while (size > 1) {
            a[i] = -1;
            int temp = 2;
            while (temp != 0) {
                i = (i + 1) % n;
                if (a[i] != -1) {
                    temp--;
                }
            }
            size--;
        }
        System.out.println(a[i]);
    }
}
