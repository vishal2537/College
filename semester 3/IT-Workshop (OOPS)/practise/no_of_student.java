class student {
    String name;
    int age;

    static int noofstudent = 0;

    student() {
        noofstudent++;
    }

    public static int getnumberofstudent() {
        return noofstudent;
    }

    public String getName() {
        return name;
    }

    public void setname(String name) {
        this.name = name;
    }

    public int getage() {
        return age;
    }

    public void setage(int age) {
        this.age = age;
    }
}

public class no_of_student {
    public static void main(String[] args) {
        // student mark = new student();
        // student tom =new student();

        // System.out.println(student.getnumberofstudent());

    }

}