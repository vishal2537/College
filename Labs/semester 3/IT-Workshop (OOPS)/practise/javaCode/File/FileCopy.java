//package File;
import java.io.*;

public class FileCopy {


public static void main(String args[]) throws IOException {
      FileInputStream in = null;
      FileOutputStream out = null;

      String directory = "F:\\File\\";
           
      try {
    	  
         in = new FileInputStream(directory+"input.txt");
         
         out = new FileOutputStream(directory+"output.txt");
         
         int c;
         
         while ( (c = in.read() ) != -1) {
        	System.out.println(c); 
            //out.write(c);
         }
      }
      catch (Exception e)
      {
    	  //System.err.print(e);
    	  
    	  //System.out.println(e);
    	  System.out.println("Exception..");
      }
      
      finally {
         if (in != null) {
            in.close();
         }
         if (out != null) {
            out.close();
         }
         System.out.println("File copy done...");
      }
   }
}