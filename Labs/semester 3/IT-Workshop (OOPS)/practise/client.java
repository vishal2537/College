import java.util.*;
import java.net.*;
import java.io.*;

// socket is just an interface between client and server to pass information
// one another

// two type of socket
// 1.simple socket
// 2.server socket

public class client {
    public static void main(String[] args) throws UnknownHostException, IOException {
        int number, temp;
        Scanner sc = new Scanner(System.in);
        Socket s = new Socket("localhost", 5555);
        Scanner sc1 = new Scanner(s.getInputStream());
        System.out.println("enter any number : ");
        number = sc.nextInt();
        PrintStream p = new PrintStream(s.getOutputStream());
        p.println(number);
        temp = sc1.nextInt();
        System.out.println(temp);

    }

}
