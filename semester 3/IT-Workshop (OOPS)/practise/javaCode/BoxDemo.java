//package InheritancePolimorphism;

class Box {
	double width;
	double height;
	private double depth;

	Box(){        // Default setting by this constructor
		width = 0.0;
		height = 0.0;
		depth = 0.0;
		System.out.println("Box default constructor is called here.. ");
	}

	Box(double w, double h, double d) {
		//volume(); //testing
		width = w;
		height = h;
		depth = d;
	}

	double volume() { // compute and return volume
		return width * height * depth;
	}
	
	void printDetails() {
		System.out.println(" width: "+width+" Height: "+height+" Depth "+depth);
	}
}

class BoxWeight extends Box {
	double weight; // weight of box

	// constructor for BoxWeight
	/*BoxWeight(double w, double h, double d, double m) {
		width = w;
		height = h;
		depth = d;
		weight = m;
	}*/
	BoxWeight()
	{
		//super();
		weight = 5.0;
		//super(double w, double h, double d); //testing..fails
	}
	BoxWeight(double w, double h, double d, double m) {
		//super(w,h,d);
		//super(); //testing
		super(w,h,d); //testing..fails
		
		printDetails();
		weight = m;
	}
	
	@Override
	void printDetails() {
		//System.out.println(" width: "+width+" Height: "+height+" Depth "+depth+" Weight: "+weight);
		super.printDetails();
		System.out.println("Weight: "+weight);
	}
}

public class BoxDemo {

	public static void main(String args[]) {
		Box mybox1 = new Box();
		
		BoxWeight mybox2 = new BoxWeight(2, 3, 4, 0.076);
		
		BoxWeight mybox3 = new BoxWeight();
		
		double vol;
		vol = mybox1.volume();
		//mybox1.printDetails();
		//System.out.println("Volume of mybox1 is " + vol);
		//System.out.println();

		vol = mybox2.volume();
		//mybox2.printDetails();
		//System.out.println("Volume of mybox2 is " + vol);
		//System.out.println("Weight of mybox2 is " + mybox2.weight);
		
		mybox3.printDetails();
	}

}
