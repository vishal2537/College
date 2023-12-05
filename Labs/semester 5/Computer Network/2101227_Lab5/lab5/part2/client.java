import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class client {
    public static void main(String[] args) {
        try {

            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);
            List<frame> receivedFrames = new ArrayList<>();
            frame receivedObject = null;
            int counter=0;
            int ruk=0;
            while (true) {
                try {
                     {
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
                        // System.out.println(counter);
                        if(counter==0)
                        ruk=(receivedObject.Window-1);
                        counter++;
                    } while (ruk-->0);
                    if (((Integer.parseInt(receivedFrames.get(0).frame_Ack_no.substring(3))) >= (receivedObject.size)))
                        break;
                } catch (IOException e) {
                    e.printStackTrace();
                    break;
                }
                out.println(receivedFrames.get(0).Frame_num+receivedFrames.get(0).Window);
                receivedFrames.clear();
                counter=0;
                out.flush();
            }
            s.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
