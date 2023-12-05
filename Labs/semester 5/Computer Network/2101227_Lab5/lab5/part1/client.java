import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class client {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);
            List<frame> receivedFrames = new ArrayList<>();
            frame receivedObject = null;
            int counter = 0;
            int ruk = 0;
            while (true) {
                try {
                    do {
                        ruk--;
                        ObjectInputStream in = new ObjectInputStream(s.getInputStream());
                        receivedObject = (frame) in.readObject();
                        receivedFrames.add(receivedObject); // Add received frame to the list
                        System.out.println("Frame data is:" + receivedObject.Frame_data);
                        System.out.println("Acki is:>>" + receivedObject.frame_Ack_no);
                        System.out.println("frame no>>" + receivedObject.Frame_num);
                        System.out.println("Ack send form client side>>" + (receivedObject.frame_Ack_no.substring(3)));
                        if (receivedObject.Frame_num == (Integer.parseInt(receivedObject.frame_Ack_no.substring(3)))) {
                            FileWriter fileWriter = new FileWriter("alice21.txt", true);
                            fileWriter.write(receivedObject.Frame_data);
                            fileWriter.close();
                        }
                        if (((Integer.parseInt(receivedObject.frame_Ack_no.substring(3))) >= (receivedObject.size)))
                            break;
                        if (counter == 0) {
                            ruk = (receivedObject.Window - 1);
                        }
                        System.out.println(ruk);
                        counter++;
                    } while (ruk > 0);
                } catch (IOException e) {
                    e.printStackTrace();
                    break;
                }
                if (((Integer.parseInt(receivedObject.frame_Ack_no.substring(3))) >= (receivedFrames.get(0).size))) {
                    System.out.println("Exiting");
                    out.println("quit");
                    out.flush();
                    break;
                }
                String lost_ack = "";
                System.out.println("Enter 1 to cause ack_lost");
                int x = sc.nextInt();
                if (x == 1) {
                    System.out.println("Enter the frame for lost ack");
                    lost_ack = sc.nextLine();
                    lost_ack = sc.nextLine();
                    out.println(lost_ack);
                    out.flush();
                } else {
                    out.println(receivedFrames.get(0).Frame_num + receivedFrames.get(0).Window);
                    receivedFrames.clear();
                    out.flush();
                }
                counter = 0;
            }
            s.close();
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
