import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;

public class q3 {

    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/institution";
        String user = "root";
        String password = "password";

        try (Connection con = DriverManager.getConnection(url, user, password);
                Statement stmt = con.createStatement();) {
            
            String query1 = "drop table if exists student_research ;";
            stmt.executeUpdate(query1);
            String query2 = "drop table if exists papers ;";
            stmt.executeUpdate(query2); 

            // add student_research relation
            String createTableQuery = "CREATE TABLE IF NOT EXISTS student_research (snum INT, paper_id VARCHAR(255))";
            stmt.executeUpdate(createTableQuery);

            // insert tuples
            String insertQuery = "INSERT INTO student_research (snum, paper_id) VALUES (115987938,'codd1970'),(115987938,'tods76chen'),(320874981,'cacm2019')";
            stmt.executeUpdate(insertQuery);

            String createTable = "CREATE TABLE IF NOT EXISTS papers (id VARCHAR(255), content longblob not null)";
            stmt.executeUpdate(createTable);

            // insert papers as blob
            String insertBlobQuery = "INSERT INTO papers (id, content) VALUES (?, ?)";
            PreparedStatement ps = con.prepareStatement(insertBlobQuery);
            ps.setString(1, "codd1970"); // paper_id
            ps.setBlob(2, new FileInputStream("C:\\Users\\Lenovo\\Desktop\\co\\sem4\\dbms\\lab9\\codd1970.pdf")); // path to paper file
            ps.executeUpdate();
            ps.setString(1, "tods76chen"); // paper_id
            ps.setBlob(2, new FileInputStream("C:\\Users\\Lenovo\\Desktop\\co\\sem4\\dbms\\lab9\\tods76chen.pdf")); // path to paper file
            ps.executeUpdate();
            ps.setString(1, "cacm2019"); // paper_id
            ps.setBlob(2, new FileInputStream("C:\\Users\\Lenovo\\Desktop\\co\\sem4\\dbms\\lab9\\cacm2019.pdf")); // path to paper file
            ps.executeUpdate();
            System.out.println("Data inserted successfully!");

        } catch (SQLException | IOException ex) {
            ex.printStackTrace();
        }
    }
}
