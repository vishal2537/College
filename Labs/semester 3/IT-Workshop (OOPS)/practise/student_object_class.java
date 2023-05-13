class student {
    int id;
    String name;
    int age;

    // getter and setter ---> encapsulation
    public int getid() // getter
    {
        return id;
    }

    public void setid(int id) // setter
    {
        this.id = id;
    }

    public String getname() {
        return name;
    }

    public void setname(String name) {
        this.name = name;
    }

    public int getage() // getter
    {
        return age;
    }

    public void setage(int age) // setter
    {
        this.age = age;
    }

}

public class student_object_class {
    public static void main(String[] args) {
        student mark = new student(); // mark --> object or instance
        // mark.id = 1;
        // mark.name = "mark";
        // mark.age = 15;

        mark.setname("mark");
        mark.setage(15);
        mark.setid(1);

        System.out
                .println(mark.getname() + " is " + mark.getage() + " years old and his student id is " + mark.getid());
        student tom = new student(); // tom --> object or instance
        tom.id = 1;
        tom.name = "tom";
        tom.age = 15;

        System.out.println(tom.name + " is " + tom.age + " years old");
    }

}
