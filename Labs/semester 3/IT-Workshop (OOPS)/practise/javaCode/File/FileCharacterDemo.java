//package File;
import java.io.FileReader;
import java.io.FileWriter;

public class FileCharacterDemo {

	public static void main(String[] args) {
		FileReader fd =null;
		FileWriter fr = null;
		
		String directory = "F:\\File\\";
		
		try {
			 fd = new FileReader(directory+"input.txt");
			 fr = new FileWriter(directory+"output.txt");
		
			int ch = 0;
			
			while ( (ch=fd.read()) != -1 ) {
				
				System.out.println(ch + " : "+(char)ch);
			}
			
			fr.write("Hi...");
			
			fd.close();
			fr.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		finally {
			System.out.println(" We are done");
		}
	}

}
