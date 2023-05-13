import java.sql.*;
import java.util.*;

public class q2 {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/institution";
        String username = "root";
        String password = "password";
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url, username, password);
            Scanner input = new Scanner(System.in);
            while (true) {
                System.out.println("-------------------------");
                System.out.println("|\t0: Exit \t|");
                System.out.println("|\t1: Q.I  \t|");
                System.out.println("|\t2: Q.II  \t|");
                System.out.println("|\t3: Q.III\t|");
                System.out.println("-------------------------");
                System.out.print("\nENTER YOUR CHOICE : ");

                int ch = input.nextInt();
                input.nextLine();
                Statement printAll = conn.createStatement();
                if (ch == 0) {
                    break;
                } else if (ch == 1) {
                    System.out.print("ENTER ROOM : ");
                    String roomName = input.nextLine();
                    String printDb = "SELECT NAME FROM CLASS WHERE ROOM='" + roomName + "'";
                    ResultSet result = printAll.executeQuery(printDb);
                    Formatter fmt = new Formatter();
                    fmt.format("\n%15s\n", "name");
                    while (result.next()) {
                        fmt.format("%25s \n", result.getString("name"));
                    }
                    System.out.println(fmt);
                } else if (ch == 2) {
                    System.out.print("ENTER COURSE NAME : ");
                    String courseName = input.nextLine();
                    String printDb = "SELECT room,meets_at as Time from class where class.name='" + courseName + "'";
                    ResultSet result = printAll.executeQuery(printDb);
                    Formatter fmt = new Formatter();
                    fmt.format("\n%15s %20s\n", "Room", "Time");
                    while (result.next()) {
                        fmt.format("%15s %20s\n", result.getString("room"), result.getString("Time"));
                    }
                    System.out.println(fmt);
                } else if (ch == 3) {
                    System.out.print("ENTER FACULTY NAME : ");
                    String facultyName = input.nextLine();
                    String printDb = "SELECT name from faculty,class where faculty.fid=class.fid and faculty.fname='"
                            + facultyName + "'";
                    ResultSet result = printAll.executeQuery(printDb);
                    Formatter fmt = new Formatter();
                    fmt.format("\n%20s\n", "courseName");
                    while (result.next()) {
                        fmt.format("%25s\n", result.getString("name"));
                    }
                    System.out.println(fmt);
                }
            }
            input.close();
            conn.close();
        } catch (SQLException e) {
            System.out.println("SqlError\n");
        } catch (Exception e) {
            System.out.println("GeneralError\n");
        }
    }
}
