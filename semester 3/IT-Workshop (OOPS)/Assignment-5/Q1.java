import java.util.ArrayList;
import java.util.Scanner;

public class Q1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<String> arr = new ArrayList<String>(1000);
        int i = 0;
        while (true) {
            System.out.println(
                    "\n\t1 - addString()\n\t2 - removeString()\n\t3 - isEmpty()\n\t4 - modifyingString()\n\t5 - printAll()\n\t6 - Exit()\n ");

            System.out.println("ENTER ANY OF ABOVE CHOICE");
            int ch = input.nextInt();

            if (ch == 1) {
                System.out.println("ENTER STRING TO ADD : ");
                input.nextLine();
                String str = input.nextLine();
                arr.add(str);
                i++;
            } else if (ch == 2) {
                System.out.print("ENTER STRING TO REMOVE : ");
                input.nextLine();
                String str = input.nextLine();
                arr.remove(str);
                i--;
            } else if (ch == 3) {
                if (i == 0) {
                    System.out.println("ARRAYLIST IS EMPTY !!");
                } else {
                    System.out.println("ARRAYLIST IS NOT EMPTY !!");
                }
            } else if (ch == 4) {
                System.out.println("ENTER INDEX TO CHANGE STRING : ");
                int index = input.nextInt();
                input.nextLine();
                String str = input.nextLine();
                arr.set(index, str);

            } else if (ch == 5) {
                for (int j = 0; j < i; j++) {
                    System.out.print(arr.get(j) + " ");
                }
                System.out.println();
            } else if (ch == 6) {
                break;
            } else {
                System.out.println("INVALID CHOICE !! TRY AGAIN !!");
            }
        }
        input.close();
    }
}