import java.sql.*;
import java.util.Scanner;
public class q2 {

    public static void main(String[] args) {

        String url = "jdbc:mysql://localhost:3306/college";
        String username = "root";
        String password = "password";
        Scanner scanner = new Scanner(System.in);

        try (Connection conn = DriverManager.getConnection(url, username, password)) {
            System.out.println("Enter student id:");
            int snum = scanner.nextInt();
            scanner.nextLine();

            // Check if the id exists in Student1
            String query = "SELECT * FROM Student1 WHERE snum = ?";
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setInt(1, snum);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                // Print the complete row corresponding to the id
                String sname = rs.getString("sname");
                String major = rs.getString("major");
                String level = rs.getString("level");
                int age = rs.getInt("age");
                System.out.printf("Student %d: %s, %s, %s, %d\n", snum, sname, major, level, age);

                // Check if the student has enrolled for any classes
                query = "SELECT cname FROM Enrolled WHERE snum = ?";
                stmt = conn.prepareStatement(query);
                stmt.setInt(1, snum);
                rs = stmt.executeQuery();

                if (rs.next()) {
                    // Print the classes for which the student has enrolled
                    System.out.printf("Enrolled classes:");
                    do {
                        String cname = rs.getString("cname");
                        System.out.printf(" %s", cname);
                    } while (rs.next());
                    System.out.printf("\n");
                } else {
                    // List the available classes
                    System.out.printf("No enrolled classes found.\n");
                    System.out.printf("Available classes:");
                    query = "SELECT name FROM Class";
                    stmt = conn.prepareStatement(query);
                    rs = stmt.executeQuery();
                    while (rs.next()) {
                        String cname = rs.getString("name");
                        System.out.printf(" %s\n", cname);
                    }
                    System.out.printf("\n");

                    // Ask for a class name to enroll
                    System.out.println("Enter class name to enroll:");
                    String cname = scanner.nextLine();

                    // Enroll the student in the given class by making an entry in Enrolled
                    query = "INSERT INTO NewEnrolled (snum, cname) VALUES (?, ?)";
                    stmt = conn.prepareStatement(query);
                    stmt.setInt(1, snum);
                    stmt.setString(2, cname);
                    int rowsAffected = stmt.executeUpdate();
                    if (rowsAffected > 0) {
                        System.out.printf("Enrolled %d in %s\n", snum, cname);
                    }
                }
            } else {
                // Print an error message if the id does not exist in Student1
                System.out.printf("Student %d not found\n", snum);
            }
            scanner.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}