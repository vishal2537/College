import java.net.*;
import java.io.*;
import java.util.*;

public class client {
    static Scanner keyboard = new Scanner(System.in);

    public static void main(String[] args) {
        try {
            Socket connection = new Socket("localhost", 6666);

            DataInputStream input = new DataInputStream(connection.getInputStream());
            DataOutputStream output = new DataOutputStream(connection.getOutputStream());

            System.out.println("ENTER FILE NAME : ");
            String fileName = keyboard.nextLine();
            output.writeUTF(fileName);
            String s = (String) input.readUTF();
            if (s.equals("-1")) {
                System.out.println("FILE NOT FOUND !!");
                System.out.println("SIMILAR FILES : " + input.readUTF());
                System.out.println("ENTER FILE NAME OR ENTER 0 TO EXIT PROGRAM : ");
                Scanner in = new Scanner(System.in);
                int choice = in.nextInt();
                in.close();
                if (choice == 0) {
                    System.exit(choice);
                } else {
                    output.writeUTF(Integer.toString(choice));
                }
                System.out.println(input.readUTF());
            } else {
                System.out.println(s);
            }
            output.close();
            connection.close();
        } catch (IOException IE) {
            IE.printStackTrace();
        }
    }
}
