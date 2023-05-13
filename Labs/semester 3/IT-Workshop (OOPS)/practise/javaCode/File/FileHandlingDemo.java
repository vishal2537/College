//package File;

import java.io.File;

public class FileHandlingDemo {

	public static void main(String[] args) {
		
		File file = new File ("BufferedReaderDemo.java");
	
		//File file = new File ("D:\\javaOutput\\data.txt");
		
		if(file.exists())
			System.out.println("File exists...");
		else
			System.out.println("File DOES NOT exist...");
		
		System.out.println("Absolute path: "+file.getAbsolutePath());
		
		//file.deleteOnExit();
		
	}

}
