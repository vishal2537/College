import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;


public class create_file_write_using_printwriter_file_class {
    public static void main(String [] args)
    {
        try{
            File file = new File("filename1.txt");
            if(!file.exists())
            {
                file.createNewFile();
            }
            PrintWriter pw = new PrintWriter(file);
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");
            pw.println("my file content");

            pw.close();
            System.out.println("done");

        } catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
