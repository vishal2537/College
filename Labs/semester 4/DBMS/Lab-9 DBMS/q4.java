import java.sql.*;
import java.util.Scanner;
import java.awt.Desktop;
import java.io.File;
import java.io.IOException;

public class q4 {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/institution";
        String username = "root";
        String password = "password";
        Scanner input = new Scanner(System.in);
        
        try {
            Connection connection = DriverManager.getConnection(url, username, password);
            System.out.println("enter student id for research info : ");
            int studentId = input.nextInt();
            String query = "SELECT * FROM student_research WHERE snum = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setInt(1, studentId);
            ResultSet resultSet = statement.executeQuery();
            String paperId;
            int snum;
            int flag = 0;

            while (resultSet.next()) {
                flag = 1;
                snum = resultSet.getInt("snum");
                paperId = resultSet.getString("paper_id");
                System.out.println("snum : " + snum);
                System.out.println("Paper ID: " + paperId);

                String filePath = paperId + ".pdf";
                File file = new File(filePath);
                if (Desktop.isDesktopSupported()) {
                    try {
                        Desktop.getDesktop().open(file);
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }

            if (flag == 0) {
                System.out.println("snum does not have any paperid");
            }

            resultSet.close();
            statement.close();
            connection.close();
        } catch (SQLException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            input.close();
        }
    }
}