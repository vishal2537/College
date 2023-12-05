import java.net.*;
import java.io.*;
import java.util.*;

public class ClientHandler implements Runnable {
  static int num = 1;
  private Socket client;
  private BufferedReader in;
  private PrintWriter out;
  private ArrayList<frame> frames;

  public ClientHandler(Socket clientSocket, ArrayList<ClientHandler> clients, ArrayList<frame> frames)
      throws IOException {
    this.client = clientSocket;
    // this.clientId="client"+String.valueOf(num);
    this.frames = frames;
    num++;
    // this.clients=clients;
    in = new BufferedReader(new InputStreamReader(client.getInputStream()));
    out = new PrintWriter(client.getOutputStream(), true);
  }

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
      if (res.compareToIgnoreCase("quit") == 0)
        return "-1";
      if (Integer.parseInt(res) >= frames.size()) {
        Thread.sleep(2000);
        return "-1";
      } else {
        x = Integer.parseInt(res);
      }
      System.out.println("Ack reviced form client side>>" + x);
    } catch (Exception e) {
      e.printStackTrace();
    }
    return String.valueOf(x);
  }

  @Override
  public void run() {
    try {
      int next = 0;
      while (true) {
        String xx = sendByte(frames, frames.get(0).Window, client, next);
        if (xx.equals("-1"))
          break;
        Thread.sleep(5000);
        next = (Integer.parseInt(xx) - 1);
      }
    } catch (Exception e) {
      System.out.println("Error here");
      e.printStackTrace();
    }

    finally {
      out.close();
      try {
        in.close();
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }
}