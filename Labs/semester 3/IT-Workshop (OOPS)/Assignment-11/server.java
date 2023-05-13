import java.net.*;
import java.io.*;
import java.util.*;

public class server {

    public static void main(String[] args) {
        try {
            ServerSocket server = new ServerSocket(6666, 2);
            Socket connection = server.accept();
            DataInputStream input = new DataInputStream(connection.getInputStream());
            DataOutputStream output = new DataOutputStream(connection.getOutputStream());
            String fileName = (String) input.readUTF();

            try {
                File file = new File(fileName);
                Scanner fileScanner = new Scanner(file);
                output.writeUTF(fileName + getFileInfo(fileScanner));
                fileScanner.close();

            } catch (FileNotFoundException fnfe) {
                output.writeUTF("-1");
                String[] contents = (new File(".")).list();
                String[] files = new String[3];
                int i = 0;
                for (String name : contents) {
                    System.out.println(name);
                    if ((new File(name)).isFile()) {
                        if (name.substring(0, 3).equals(fileName.substring(0, 3))) {
                            files[i] = name;
                            i++;
                        }
                    }
                }
                output.writeUTF(files[0] + " " + files[1] + " " + files[2]);
                int choice = Integer.parseInt(input.readUTF());
                Scanner secondFileScanner = new Scanner(contents[choice]);
                output.writeUTF(contents[choice] + getFileInfo(secondFileScanner));
                secondFileScanner.close();
            }

            input.close();
            connection.close();
            server.close();
        } catch (IOException IE) {

        }
    }

    public static String getFileInfo(Scanner fileScanner) {
        ArrayList<String> words = new ArrayList<>();
        int wordCount = 0;
        int numberOfLines = 0;
        while (fileScanner.hasNextLine()) {
            String[] line = fileScanner.nextLine().split(" ");
            for (String word : line) {
                words.add(word);
            }
            wordCount = wordCount + words.size();
            numberOfLines++;
        }

        return " WORD COUNT : " + Integer.toString(wordCount) + " LINE COUNT : " + Integer.toString(numberOfLines);
    }

}
