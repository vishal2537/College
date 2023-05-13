package InheritancePolimorphism;

import java.util.ArrayList;
import java.util.Collections;

abstract class Persons  implements Comparable<Persons> {
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
	
	
	public int compareTo(Persons p)
	{
		return (this.age - p.age);
		/*
		Return	+ve : if curr object > arg object, 	
				-ve  : if curr object < arg object, 	
				0    : if curr object = arg object
 		*/
		
	}
		
}

class Students extends Persons
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

class FacultyMember extends Persons
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
public class PersonDemoSorting {

	public static void main(String[] args)
	{
		Students s1 = new Students(), s2 = new Students();
		FacultyMember f1 = new FacultyMember(), f2 = new FacultyMember();
		
		s1.setData("A", 10, 9.2); s2.setData("B", 10, 7.0);
		f1.setData("C", 70, 300); f2.setData("D", 75, 50);
		
		ArrayList<Persons> PersonList = new ArrayList();
		
		PersonList.add(s2); PersonList.add(s1); PersonList.add(f2); PersonList.add(f1);
		
		for(Persons p:PersonList)
		{
			p.printDetails();
			//System.out.println(p);
		}
		
		System.out.println("\nSorting based on age: \n");		
		Collections.sort(PersonList);
		
		for(Persons p:PersonList)
		{
			p.printDetails();
			//System.out.println(p);
		}
	}

}
