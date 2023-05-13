import java.util.*;
import java.net.*;
import java.io.*;

public class server {
    public static void main(String[] args) throws IOException {
       
        int number ,temp;
        ServerSocket s1 = new ServerSocket(5555,2);
        Socket ss = s1.accept();

        Scanner sc = new Scanner(ss.getInputStream());
        number = sc.nextInt(); 

        temp = number *2;

        PrintStream p = new PrintStream(ss.getOutputStream());
        p.println(temp);
    }
}
