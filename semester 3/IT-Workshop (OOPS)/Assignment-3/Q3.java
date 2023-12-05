import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("ENTER THE SIZE OF ARRAY: ");
        int n = input.nextInt();
        int C = 0;
        int[] array;
        array = new int[n];
        int[] temp = new int[n];

        System.out.println("ENTER THE ELEMENT: ");
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }

        input.close();
        temp[0] = 0;
        for (int i = 1; i < temp.length; i++) {
            C = 0;
            for (int j = 0; j < i; j++) {
                if (array[j] > array[i]) {
                    C++;
                }
            }
            temp[i] = C;
        }
        for (int i = 0; i < temp.length; i++) {
            System.out.print(temp[i] + " ");
        }
        input.close();
    }
}
