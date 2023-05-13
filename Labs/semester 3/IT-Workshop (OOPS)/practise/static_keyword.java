class hello {
    static int age;
    public static String dosomething(String message) {
        return message;
    }

    public String dosomethingnelse(String message) {
        return message;
    }
}

public class static_keyword {

    // what does the static keyword do in a class?
    public static void main(String[] args) {
        // static members belong to the class instead of a specific instance.
        hello hello1 =new hello();

        //static member directly access from class to main  funtion without creating an object
        hello.dosomething("static");

        // non static method can be access  using object/ instance of a class
        // satic method should access using class itself and share by instances.
        
        hello.age=10;
        System.out.println(hello.age);
       
        hello1.dosomethingnelse("hii");

        // hello hello2 =new hello();
        hello.age=50;
        System.out.println(hello.age);


        // hello hello3 =new hello();

        // hello hello1 =new hello();

    }

}
