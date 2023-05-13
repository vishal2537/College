import java.util.Scanner;

public class Q6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the String");
        String str = input.nextLine();

        int c = 1;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                c++;
            }
        }

        input.close();
        System.out.println("entered string is");
        System.out.println(str);
        System.out.println("total word " + c);

    }
}