//package File;
import java.io.*;
import java.util.*;

public class FileCopyAnother {

   public static void main (String args[]) throws Exception{  
      FileInputStream in = null;
      FileOutputStream out = null;

      String directory = "F:\\File\\";
           
     
    	  
         in = new FileInputStream(directory+"input.txt");
         
         out = new FileOutputStream(directory+"output.txt");
         
         int c;
         
         while ( (c = in.read() ) != -1) {
        	 
            out.write(c);
         }
     
      
      
         if (in != null) {
            in.close();
       
         if (out != null) {
            out.close();
         }
         System.out.println("File copy done...");
      }
   }
}