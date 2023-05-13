//package File;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class BufferedReaderDemo {

	public static void main(String[] args) {
		
		String filename = "data.csv";
		
		//String directory = "D:\\Academics\\JMS_CS202_IT_Workshop-I\\2022_Monsoon_Aug-Nov\\JavaCode\\CodesCS202_FileHnadling\\";
		String directory = "F:\\File\\";
		File file = new File(directory+filename);
		
		String line = "";
		
		try {
			FileReader fileReader = new FileReader(file);
			BufferedReader br = new BufferedReader(fileReader);
			//System.out.println("Name \t Roll \t Age \n");
			while ((line = br.readLine()) != null) {
				//String str;
				for(String str:line.split(",") ) {
					
					System.out.print(str +"\t");
								
				}
				
				//System.out.print(line);		
										
				System.out.println();
		        
			}
			br.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
			
		
	}

}
