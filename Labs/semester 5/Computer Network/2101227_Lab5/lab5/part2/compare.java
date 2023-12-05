import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class compare {
    public static void main(String[] args) {
        String filePath1 = "alice21.txt";
        String filePath2 = "alice29.txt";

        try {
            BufferedReader reader1 = new BufferedReader(new FileReader(filePath1));
            BufferedReader reader2 = new BufferedReader(new FileReader(filePath2));

            String line1 = reader1.readLine();
            String line2 = reader2.readLine();
            int lineNum = 1; // To track the line number being compared

            boolean filesAreEqual = true;

            while (line1 != null || line2 != null) {
                if(lineNum==3609)break;
                if (line1 == null || line2 == null || !line1.equals(line2)) {
                    System.out.println("Files are not equal. Difference found at line " + lineNum);
                    filesAreEqual = false;
                    break;
                }

                line1 = reader1.readLine();
                line2 = reader2.readLine();
                lineNum++;
            }

            if (filesAreEqual) {
                System.out.println("Files are equal.");
            }

            reader1.close();
            reader2.close();
        } catch (IOException e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }
}
