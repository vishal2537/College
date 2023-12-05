
import java.sql.*;

public class q3 {
    public static void main(String[] args) {
        String DB_URL = "jdbc:mysql://localhost/institution";
        String USER = "root";
        String PASS = "password";

        Connection conn = null;
        Statement stmt = null;
        try {
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);
            stmt = conn.createStatement();

            String query1 = "drop table if exists student_research ;";
            stmt.executeUpdate(query1);

            // Create student_research table
            String sql = "CREATE TABLE student_research " +
                    "(snum INTEGER not NULL, " +
                    " paper_id VARCHAR(255) not NULL, " +
                    " PRIMARY KEY ( snum, paper_id ))";
            stmt.executeUpdate(sql);
            System.out.println("student_research relation added to Lab1Database.");

            System.out.println("Inserting tuples into student_research relation...");
            String sql1 = "INSERT INTO student_research (snum, paper_id) " +
                    "VALUES (115987938,'codd1970'),(115987938,'tods76chen'),(320874981,'cacm2019')";
            stmt.executeUpdate(sql1);
            System.out.println("Tuples inserted successfully");

            stmt.close();
            conn.close();
        } catch (SQLException se) {
            se.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (stmt != null)
                    stmt.close();
            } catch (SQLException se2) {
            }
            try {
                if (conn != null)
                    conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
    }
}
