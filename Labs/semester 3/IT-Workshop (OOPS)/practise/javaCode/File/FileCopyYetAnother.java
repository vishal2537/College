package File;
import java.io.*;

public class FileCopyYetAnother {


public static void main(String args[]) {
      FileInputStream in = null;
      FileOutputStream out = null;

      String directory = "D:\\Academics\\JMS_CS202_IT_Workshop-I\\2022_Monsoon_Aug-Nov\\JavaCode\\CodesCS202_FileHnadling\\";
           
      try {
    	  
         in = new FileInputStream(directory+"input.txt");
         
         out = new FileOutputStream(directory+"output.txt");
         
         int c;
         
         while ( (c = in.read() ) != -1) {
        	 
            out.write(c);
         }
         
         in.close();
         out.close();
      }
      catch (Exception e)
      {
    	  //System.err.print(e);
    	  
    	  //System.out.println(e);
    	  System.out.println("Exception..");
      }
      
      finally {
            System.out.println("File copy done...");
      }
      
   }
}