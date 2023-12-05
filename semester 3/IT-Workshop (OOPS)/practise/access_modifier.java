// import javax.annotation.processing.Generated;
// import javax.print.attribute.SetOfIntegerSyntax;

class student {
    // String name;
    // int age;
    // public String name;
    // public int age;

    private String name;
    private int age;

    public int getAge() {
        return age;
    }
    public String getName() {
        return name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setName(String name) {
        this.name = name;
    }


    // static int noofstudent = 0;
    // student() {
    // noofstudent++;
    // }

    // public static int getnumberofstudent() {
    // return noofstudent;
    // }

    // public String getName() {
    // return name;
    // }

    // public void setname(String name) {
    // this.name = name;
    // }

    // public int getage() {
    // return age;
    // }

    // public void setage(int age) {
    // this.age = age;
    // }
}

// ACCESS LEVELS
/*
 * MODIFIER --class--- PACKAGE--- SUBCLASS--- WORLD
 * PULIC-- YES--- YES--- -YES ---YES
 * PROTECTED--- YES ---YES ---YES ---NO
 * NO MODIFIER ----YES ----YES---- NO----NO
 * PRIVATE ----YES---- NO---- NO ----NO
 */
public class access_modifier {
    public static void main(String[] args) {
        student std = new student();
        // std.name = "maark";
        std.setName("maark");
        System.out.println(std.getName());

    }

}
