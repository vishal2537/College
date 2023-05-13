import java.util.Scanner;

public class second {
    public static void main(String []args)
    {
        int variable =10;
        System.out.println(variable);

        Scanner scan =new Scanner( (System.in));
        int user_input;
        user_input=scan.nextInt();
        scan.nextLine();

        System.out.println("enter value " + user_input);

        String se;
        se = scan.nextLine();

        System.out.println("enter value " + se);
    }
}
