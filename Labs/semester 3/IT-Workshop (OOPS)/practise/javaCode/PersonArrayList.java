//package array;

import java.util.*;

abstract class Persons {
	String name;
	int age;
	
	void setData(String name1, int age1)
	{
		name = name1;
		age = age1;
	}
	
	void printDetails()
	{
		System.out.print("Name: "+name+"  Age: "+age);
	}
	
	abstract void exceptional();
	
			
}

class Student extends Persons
{
	double cpi;
	
	void setData(String name1, int age1, double cpi1)
	{
		super.setData(name1, age1);
		cpi = cpi1;
	}
	
	void printDetails()
	{
		System.out.println();
		super.printDetails();
		System.out.print(" CPI: "+cpi);
	}
	
	void exceptional()
	{
		if (cpi > 9.0) System.out.print("   Exceptional ");
	}
	
}

class Faculty extends Persons
{
	float noOfPub;
	
	void setData(String name1, int age1, int nop)
	{
		super.setData(name1, age1);
		noOfPub = nop;
	}
	
	void printDetails()
	{
		System.out.println();
		super.printDetails();
		System.out.print(" No of Pub: "+noOfPub);
	}
	
	void exceptional()
	{
		if (noOfPub > 100) System.out.print("   Exceptional ");
	}
} 

public class PersonArrayList {

	public static void main(String[] args)
	{
		Student s1 = new Student(), s2 = new Student();
		Faculty f1 = new Faculty(), f2 = new Faculty();
		
		s1.setData("A", 10, 9.2); s2.setData("B", 10, 7.0);
		f1.setData("C", 70, 300); f2.setData("D", 75, 50);
		
		
		//s1.printDetails();
		//f1.printDetails();
		
		
		
		/** Array List demonstration.... */ 
		
		ArrayList<Persons> PersonList = new ArrayList<Persons>();
		
		PersonList.add(s1); PersonList.add(f1); PersonList.add(s2); PersonList.add(f2); 
		
				
		for(Persons p:PersonList)
		{
			p.printDetails();
			
			//p.exceptional();
		
		}
	}

}
