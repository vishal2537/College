  const express = require("express");
  const mysql = require("mysql2");
  const bodyParser = require("body-parser");
  const app = express();
  const port = process.env.PORT || 5001;
  const path = require("path");

  const cors = require("cors");
  app.use(cors());

  const pool = mysql.createPool({
    // host: "localhost",
    // user: "root",
    host: "contactform.cfmfrfg6ylcp.ap-south-1.rds.amazonaws.com",
    user: "admin",
    password: "password",
    database: "contactform",
  });

  pool.getConnection(function (err, connection) {
    pool.query(
      "create table if not exists contacts (id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(255) NOT NULL,email VARCHAR(255) NOT NULL,message TEXT NOT NULL);",
      function (err, result) {
        if (err) {
          console.error(err);
          // return res.status(500).json({ status: false, error: "Database error" });
        }
        console.log("table created!");
      }
    );
  });

  app.use(bodyParser.urlencoded({ extended: true }));
  app.use(express.static(path.join(__dirname, "public")));
  app.set("view engine", "ejs");
  app.use(bodyParser.json());

  app.post("/submit", async (req, res) => {
    try {
      const { name, email, message } = req.body;
      const sql = "INSERT INTO contacts (name, email, message) VALUES (?, ?, ?)";
      const values = [name, email, message];

      pool.query(sql, values, (err, result) => {
        if (err) {
          console.error(err);
          res.send("Error submitting the form.");
        } else {
          console.log("Form submitted successfully");
          res.status(200).json({ message: "hi" });
        }
      });
    } catch (error) {
      console.log(error);
      res.status(501).json(error);
    }
  });

  app.get("/submissions", async (req, res) => {
    const sql = "SELECT * FROM contacts ORDER BY id DESC";
    pool.query(sql, (err, results) => {
      if (err) {
        console.error(err);
        res.send("Error fetching submissions.");
      } else {
        res.status(200).json({ submissions: results });
      }
    });
  });

  app.delete("/deletesubmission/:id", async (req, res) => {
    const submissionId = req.params.id;
    const sql = "DELETE FROM contacts WHERE id = ?";

    pool.query(sql, [submissionId], (err, result) => {
      if (err) {
        console.error(err);
        res.send("Error deleting submission.");
      } else {
        console.log("Submission deleted successfully");
        res.status(200).json({ deletesubmission: result });
      }
    });
  });

  app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
  });
