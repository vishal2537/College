
// package sem5_computer_network.lab1;
// import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.net.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class sever {
  public static ArrayList<frame> ara_ara() {
    ArrayList<frame> frames = new ArrayList<frame>();
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number of frame:");
    int n = sc.nextInt();
    System.out.println("Enter the window size");
    int si = sc.nextInt();
    int frame_no = 1;
    for (int i = 0; i < n; i++) {
      try (FileWriter fileWriter = new FileWriter("alice29.txt", true)) {
        System.out.println("Enter the data [" + frame_no + "]:");
        frame obj1 = new frame();
        obj1.Frame_data = sc.nextLine();
        if(i==0)
        obj1.Frame_data = sc.nextLine();
        obj1.Frame_num = frame_no;
        obj1.size = n;
        obj1.Window = si;
        obj1.frame_Ack_no = "Ack" + String.valueOf(frame_no);
        frame_no++;
        frames.add(obj1);
        fileWriter.write(obj1.Frame_data);
        fileWriter.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    sc.close();
    return frames;
  }

  private static ArrayList<ClientHandler> clients = new ArrayList<>();
  private static ExecutorService pool = Executors.newFixedThreadPool(5);

  public static void main(String args[]) {
    ArrayList<frame> frames = new ArrayList<frame>();
    frames = ara_ara();
    try {
      ServerSocket ss = new ServerSocket(5555);
      while (true) {
        Socket s = ss.accept();
        System.out.println("\nSystem connect successfully\n");
        ClientHandler newclient = new ClientHandler(s, clients,frames);
        clients.add(newclient);
        pool.execute(newclient);
        if ("ack".compareTo("aaa") == 0) {
          break;
        }
      }
      ss.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
