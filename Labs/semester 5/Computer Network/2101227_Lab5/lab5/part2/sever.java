import java.net.*;
import java.io.*;
import java.util.*;

public class sever {
  static int prev = -1;

  public static String sendByte(ArrayList<frame> frames, int x, Socket s, int next) {
    BufferedReader in = null;
    ObjectOutputStream out = null;
    try {
      for (int i = next; i < next + x; i++) {
        if (i >= frames.size()) {
          Thread.sleep(2000);
          return "-1";
        }
        out = new ObjectOutputStream(s.getOutputStream());
        System.out.println("send  Frame =" + i);
        out.writeObject(frames.get(i));
        out.flush();
      }
      in = new BufferedReader(new InputStreamReader(s.getInputStream()));
      String res = in.readLine();
      if (res == null)
        return "-1";
      if (Integer.parseInt(res) >= frames.size()) {
        Thread.sleep(2000);
        return "-1";
      }
      if (res.compareToIgnoreCase("quit") == 0)
        return "-1";
      else
        x = Integer.parseInt(res);
      System.out.println("Ack reviced form client side>>" + x);
    } catch (Exception e) {
      e.printStackTrace();
    }
    return String.valueOf(x);
  }

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

  public static void main(String args[]) {
    ArrayList<frame> frames = new ArrayList<frame>();
    frames = ara_ara();
    Scanner sc = new Scanner(System.in);
    // System.out.println("Enter the window size");
    try {
      ServerSocket ss = new ServerSocket(5555);
      Socket s = ss.accept();
      System.out.println("\nSystem connect successfully\n");
      int next = 0;
      while (true) {
        String xx = sendByte(frames, frames.get(0).Window, s, next);
        if (xx.equals("-1"))
          break;
        Thread.sleep(5000);
        next = (Integer.parseInt(xx) - 1);
      }
      s.close();
      ss.close();
      sc.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
