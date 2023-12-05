
class Student
{
	int age;
	int roll;
	
	static int studentCount;
	
	Student()
	{
		studentCount++;
		
		//System.out.println("Total students: "+studentCount);
	}
	public void getData(int a, int r)
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
public class StudentDemo {

	public static void main(String[] args) 
	{
		Student s1 = new Student();
		Student s2 = new Student();
		
		s1.getData(2, 20);
		s1.showData();
		Student.studentCount();

	}

}
