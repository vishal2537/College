import java.sql.*;
import java.util.ArrayList;
import java.io.*;

public class q1 {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/institution";
        String username = "root";
        String password = "password";
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;

        ArrayList<String> tableNames = new ArrayList<String>();
        try {
            conn = DriverManager.getConnection(url, username, password);
            stmt = conn.createStatement();

            rs = stmt.executeQuery("SHOW TABLES FROM INSTITUTION");
            while (rs.next()) {
                tableNames.add(rs.getString(1));
            }

            System.out.println("\n\nWHICH TABLE DO YOU WANT PRINT?");
            for (int i = 0; i < tableNames.size(); i++) {
                System.out.println("\t" + i + ": " + tableNames.get(i));
            }

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String tableName = br.readLine();

            rs = stmt.executeQuery("SELECT * FROM " + tableNames.get(Integer.parseInt(tableName)));
            ResultSetMetaData rsmd = rs.getMetaData();
            int columnsNumber = rsmd.getColumnCount();

            for (int i = 1; i <= columnsNumber; i++) {
                String columnName = rsmd.getColumnName(i);
                System.out.format("%28s", columnName);

            }
            System.out.println("");
            while (rs.next()) {
                for (int i = 1; i <= columnsNumber; i++) {
                    String columnValue = rs.getString(i);
                    System.out.format("%28s", columnValue);
                }
                System.out.println("");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }
}