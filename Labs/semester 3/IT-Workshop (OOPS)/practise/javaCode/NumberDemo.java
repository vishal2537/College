class Number
{
	int item1;
	int item2;
	
	Number (int i1, int i2)
	{
		item1 = i1;
		item2 = i2;
	}
	public void swap(int i1, int i2)
	{
		int temp = i1;
		i1= i2;
		i2 = temp;
	}	
	
	public void swap(Number n)
	{
		int temp = n.item1;
		n.item1 = n.item2;
		n.item2 = temp;
	}
	public void swap()
	{
		System.out.println("hi..");
		int temp = item1;
		item1= item2;
		item2 = temp;
	}
	public boolean compare()
	{
		//System.out.println("Inside comparison");
		return (item1 < item2)? true:false;
	}
	/*public void swap(int i1, int i2)
	{
		item1= i2;
		item2 = i1;
	}*/
}

public class NumberDemo
{
	public static void main(String args[])
	{
		int num1 = 2;
		int num2 = 3;
		
		Number num = new Number (num1, num2);
		
		System.out.println("Items before swap "+num.item1+" and "+num.item2);
		
		//num.swap(num.item1, num.item2);
		//System.out.println("Items after FIRST swap "+num.item1+" and "+num.item2);
		
		num.swap(num);
		System.out.println("Items after SECOND swap "+num.item1+" and "+num.item2);
		
		//num.swap();
		//System.out.println("Items after THIRD swap "+num.item1+" and "+num.item2);
		
		Number [] arrayNum = new Number[5];
		
		for(int index=0; index < arrayNum.length; index++) {
			arrayNum[index] = new Number (num1, num2);
			if (arrayNum[index].compare()) {
				System.out.println("num1 less than num2");
			}
		}
		
		
	}
}