//package InheritancePolimorphism;

class A {
	A() {
		System.out.println("\n Class A constructor is called...\n");
	}
	A(int i) {
		System.out.println("\n Class A para constructor is called...\n");
	}
}

class B extends A {
	B() {
		System.out.println("\n Class B constructor is called...\n");
	}
	B(int i) {
		super(i);
		System.out.println("\n Class B PARA constructor is called...\n");
	}
}

class C extends B {
	C() {
		System.out.println("\n Class C constructor is called...\n");
	}
	
	C(int i) {
		
		super(i);
		System.out.println("\n Class C PARA constructor is called...\n");
		
	}
}
public class ConstructorDemo {

	public static void main(String[] args) {
		
		//A a = new A();
		B b = new B();
		// C cObj = new C();
		
		// C cc = new C(2);
	}

}
