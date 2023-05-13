import java.util.Scanner;


public class Person {
	String name;
	int age;
	
	void setData() {
		Scanner s = new Scanner(System.in);
		
		System.out.println("enter name: ");
		name = s.nextLine();
		
		System.out.println("enter age: ");
		age = s.nextInt();
		//s.close();
	}
	void showData()
	{
		System.out.println("Name: "+name +" Age: "+age);
	}
	
	void oldPerson()
	{
		if (age > 60)
			System.out.println(name + "is old with age "+age);
	}

	public static void main(String[] args) {
		
		Person [] customer = new Person [2];
		
		for(int i=0;i<customer.length;i++){
		customer[i] = new Person();
		customer[i].setData();
		}
		
		for(int i=0;i<customer.length;i++)
		{
			customer[i].showData();
		}
		
		//Person p = new Person();
		//p.setData();
		//p.showData();
		

	}

}
