import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Scanner;
import java.awt.Desktop;

public class q4 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String url = "jdbc:mysql://localhost:3306/institution";
        String user = "root";
        String password = "password";
        System.out.println("Enter snum : ");
        int snum = input.nextInt();
        input.close();

        try (Connection con = DriverManager.getConnection(url, user, password);
                PreparedStatement stmt = con.prepareStatement(
                        "SELECT papers.id, papers.content FROM student_research JOIN papers ON student_research.paper_id = papers.id WHERE student_research.snum = ?")) {
            stmt.setInt(1, snum);
            ResultSet rs = stmt.executeQuery();
            int flag = 0;

            // save papers to files
            while (rs.next()) {
                flag = 1;
                String paperId = rs.getString("id");
                Blob paperBlob = rs.getBlob("content");
                InputStream is = paperBlob.getBinaryStream();
                try (FileOutputStream fos = new FileOutputStream("paper" + paperId + ".pdf")) {
                    byte[] buffer = new byte[1024];
                    int bytesRead;
                    while ((bytesRead = is.read(buffer)) != -1) {
                        fos.write(buffer, 0, bytesRead);
                    }
                    System.out.println("Paper " + paperId + " retrieved successfully!");

                } catch (IOException ex) {
                    ex.printStackTrace();
                }
                String filePath = "paper" + paperId + ".pdf";
                File file = new File(filePath);
                if (Desktop.isDesktopSupported()) {
                    try {
                        Desktop.getDesktop().open(file);
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            } 
            if(flag == 0)
            {
                System.out.println(snum + " does not have any paperid");
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }
}

