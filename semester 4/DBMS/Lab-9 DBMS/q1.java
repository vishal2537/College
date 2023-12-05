import java.sql.*;
import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/college";
        String username = "root";
        String password = "password";
        Connection conn = null;
        Statement stmt = null;
        Scanner input = new Scanner(System.in);

        try {
            Class.forName("com.mysql.jdbc.Driver");
            conn = DriverManager.getConnection(url, username, password);
            stmt = conn.createStatement();

            String query1 = "drop table if exists student1 ;";
            stmt.executeUpdate(query1);

            String query2 = "drop table if exists newenrolled ;";
            stmt.executeUpdate(query2);

            // Create Student1 table
            String sql = "CREATE TABLE if not exists student1 like student";
            stmt.executeUpdate(sql);

            String que = "select snum from student ;";
            ResultSet rs2 = stmt.executeQuery(que);

            while (rs2.next()) {
                int snum = rs2.getInt("snum");
                System.out.printf("snum : " + snum);
                System.out.printf("\n");
            }

            System.out.println("Student1 table created successfully.");
            System.out.println("enter number of student to add in student1 : ");
            int inp = input.nextInt();

            
            System.out.println("Enter student snum, sname, major, level, age :");
            for (int i = 0; i < inp; i++) {
                System.out.print("Enter student snum: ");
                int snum = input.nextInt();
                input.nextLine();
                PreparedStatement findStudent = conn.prepareStatement("select * from student where snum = ?");
                findStudent.setInt(1, snum);
                ResultSet rs1 = findStudent.executeQuery();
                if (rs1.isBeforeFirst()) {
                    PreparedStatement studentInfo = conn
                            .prepareStatement("insert into student1 select * from student where snum = ?");
                    studentInfo.setInt(1, snum);
                    studentInfo.executeUpdate();
                } else {
                    System.out.print("Enter student sname: ");
                    String sname = input.nextLine();
                    System.out.print("Enter student major: ");
                    String major = input.nextLine();
                    System.out.print("Enter student level: ");
                    String level = input.nextLine();
                    System.out.print("Enter student age: ");
                    int age = input.nextInt();

                    sql = "INSERT INTO student1 (snum, sname, major, level, age) " +
                            "VALUES (" + snum + ", '" + sname + "', '" + major + "', '" + level + "', " + age + ")";

                    stmt.executeUpdate(sql);
                }
                System.out.println("Student " + i + " added to Student1 successfully.");
            }
            // Create NewEnrolled table
            sql = "CREATE TABLE if not exists NewEnrolled LIKE Enrolled";
            stmt.executeUpdate(sql);
            System.out.println("NewEnrolled table created successfully.");
            input.close();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (stmt != null) {
                    conn.close();
                }
            } catch (SQLException se) {
            }
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
    }
}