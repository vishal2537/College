//package array;

import java.util.ArrayList;

class Students
{
	int age;
	int roll;
	
	static int studentCount;
	
	Students()
	{
		roll = 0;
		studentCount++;
		
		//System.out.println("Total students: "+studentCount);
	}
	public void putData(int a, int r)
	{
		age = a;
		roll = r;
	}
	
	public void showData()
	{
		System.out.print("age: "+ age +" roll: "+roll+"\n");
	}
	
	public static void studentCount()
	{
		System.out.println("Total students: "+studentCount);
	}
}


public class StudentArrayList {

	public StudentArrayList() 
	{
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		ArrayList<Students> studentlist = new ArrayList<Students>();
		
		
		for(int index = 0; index < 3; index++)
		{
			Students s = new Students();
			studentlist.add(s);
			s.putData(14, 1);
		}
		
		for(int index = 0; index < 3; index++)
		{
			Students s = studentlist.get(index);
			s.showData();
		}

	}

}
