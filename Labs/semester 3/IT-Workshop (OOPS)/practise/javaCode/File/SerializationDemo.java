//package File;

import java.io.*;

class Employee implements Serializable {
	
	String name;
	String address;
	String PIN;
	
	Employee(String name, String address, String pin ) {
		this.name = name; this.address = address; this.PIN = pin;
	}
	
	String getDetails() {
		return ""+name+" "+address+" "+PIN;
				
	}
}

public class SerializationDemo {

   public static void main(String [] args) {
	   
      Employee e = new Employee("Abcddddd", "Ghy", "781015");
      
      Employee e2 = new Employee("Bcd", "Blp", "781011");
      
      Employee e3 = new Employee("Xyz", "Delhi", "781019");
      
      String directory = "F:\\File\\";
      
      try {
         FileOutputStream fileOut = new FileOutputStream(directory+"Employee.ser");
    	 //FileOutputStream fileOut = new FileOutputStream(directory+"Emp.txt");
         
         ObjectOutputStream out = new ObjectOutputStream(fileOut);
         
         out.writeObject(e);
         
         out.writeObject(e2);
         
		 for(int i=0; i<20; i++)
         out.writeObject(e3);
         
         out.close();
         
         fileOut.close();
         
         System.out.printf("Serialized data is saved in "+ directory);
      } catch (IOException i) {
         i.printStackTrace();
      }
      
      System.out.println();
      
     
      try {
    	      	  
    	  FileInputStream fin = new FileInputStream(directory+"employee.ser");
    	  
    	  ObjectInputStream oim = new ObjectInputStream(fin);
    	  
    	  while (true) {
    		  
    		  e = (Employee) oim.readObject(); 
        	  
    		  
        	  System.out.println(e.getDetails());
    	  }
    	   	  
      }
      catch (EOFException eof) {
    	System.out.println(" .... End of File ... ");  
      }
      catch (IOException ioe) {
    	  
      }
      catch(ClassNotFoundException cnf) {
    	  
      }
      
      
   }
}