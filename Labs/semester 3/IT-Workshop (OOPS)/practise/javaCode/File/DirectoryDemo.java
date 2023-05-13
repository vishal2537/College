//package File;

import java.io.File;

public class DirectoryDemo {

	public static void main(String[] args) {
		File file = null;
	      String[] paths;
	  
	           		
	         file = new File("C:\\");
			 
			 //file = new File (args[0]);

	         paths = file.list();

	         for(String path:paths) 
	         {
	        	 System.out.println(path);
	         }
	      
	}

}
