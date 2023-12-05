//package InheritancePolimorphism;

class Point {
	int x, y;

	Point(int x1, int y1) { // It is a constructor
		x = x1;
		y = y1;
	}

	float distance(int x1, int y1) { // One definition of distance
		int dx = x - x1;
		int dy = y - y1;
		System.out.println("Inside 2D class, distance using coordinate");
		return (float) Math.sqrt(dx * dx + dy * dy);
	}

	float distance(Point p) { // Overloaded definition of distance .
		System.out.println("Inside 2D class, distance using another point ");
		return distance(p.x, p.y);
	}
}

class Point3D extends Point {
	int z;

	Point3D(int x1, int y1, int z1) { // Constructor of Point3D
		super(x1, y1);
		this.z = z1;
	}

	float distance(int x1, int y1, int z1) { // Another definition of distance
		int dx = x - x1;
		int dy = y - y1;
		int dz = z - z1;
		System.out.println("Inside 3D class, distance using coordinate");
		return (float) Math.sqrt(dx * dx + dy * dy + dz * dz);
	}

	float distance(Point3D pt) {
		System.out.println("Inside 3D class, distance using coordinate");
		return distance(pt.x, pt.y, pt.z);
	}

	void testFunction() {
		System.out.println("Inside 3D");
	}
}

public class PolymorphDemo {
	public static void main(String args[]) {

		Point p1 = new Point(10, 5); // 2-D point

		Point3D p3 = new Point3D(5, 10, 5); // 3-D point

		Point p2 = new Point(4, 1); // another 2-D point
		Point p4 = new Point3D(2, 3, 4); // another 3-D point

		// Same object p1 is calling distance method BUT their signatures are different
		float d0 = p1.distance(0, 0);
		float d1 = p1.distance(p2);

		float d2 = p4.distance(p3); // distance is called for a different object; p4 is of type Point3D

		System.out.println("Distance from P2 to Origin, d0 = " + d0);
		System.out.println(" Distance from P2 to P1, d1 = " + d1);
		System.out.println("Distance from P3 to P4, d2= " + d2);

		// p4.testFunction();
	}
}
