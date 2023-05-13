// an exception is an event which occur during the execution of 
// a program that disrupts the normal flow of the program's instruction.

public class exception {
    public static void main(String[] args) {
        int b[] = new int[2];
        try {
            int a = 100 / 0;
            System.out.println(b[3]);
        } catch (ArithmeticException e) {
            System.out.println(e); // print type of exception of exception handle

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        }
        catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("----");
    }
}
