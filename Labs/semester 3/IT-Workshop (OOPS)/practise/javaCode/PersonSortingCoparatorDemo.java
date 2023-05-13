package InheritancePolimorphism;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class AgeComparator implements Comparator<Persons> 
{
	public int compare (Persons s1, Persons s2) 
	{
		return s1.age - s2.age;
	}
	
}

class NameLengthComparator implements Comparator<Persons> 
{
	public int compare (Persons s1, Persons s2) 
	{
		return s1.name.length() - s2.name.length();
	}
	
}


public class PersonSortingCoparatorDemo {

	public static void main(String[] args)
	{
		Students s1 = new Students(), s2 = new Students();
		FacultyMember f1 = new FacultyMember(), f2 = new FacultyMember();
		
		s1.setData("Abc", 10, 9.2); s2.setData("BDG", 10, 7.0);
		f1.setData("Cy", 70, 300); f2.setData("DKZP", 75, 50);
		
		ArrayList<Persons> PersonList = new ArrayList();
		
		PersonList.add(s2); PersonList.add(s1); PersonList.add(f2); PersonList.add(f1);
		
		for(Persons p:PersonList)
		{
			p.printDetails();
			//System.out.println(p);
		}
		
		System.out.println("\nSorting based on age: \n");		
		//Collections.sort(PersonList);
		Collections.sort(PersonList, new AgeComparator());
		
		for(Persons p:PersonList)
		{
			p.printDetails();
			//System.out.println(p);
		}
		
		System.out.println("\nSorting based on name length: \n");		
		Collections.sort(PersonList, new NameLengthComparator());
		
		for(Persons p:PersonList)
		{
			p.printDetails();
			//System.out.println(p);
		}
		
	}

}
