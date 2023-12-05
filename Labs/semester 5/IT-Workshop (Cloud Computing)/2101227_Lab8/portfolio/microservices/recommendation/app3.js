const express = require("express");
const mysql = require("mysql2");
const bodyParser = require("body-parser");
const app = express();
const path = require("path");
const port = process.env.PORT || 5003;

const cors = require("cors");
app.use(cors());

const pool = mysql.createPool({
  // host: "localhost",
  host: "contactform.cfmfrfg6ylcp.ap-south-1.rds.amazonaws.com",
  // user: "root",
  user: "admin",
  password: "password",
  // database: "contactform",
  database: "recommendation",
});

pool.getConnection(function (err, connection) {
  pool.query(
    "CREATE TABLE IF NOT EXISTS recommendations (id INT AUTO_INCREMENT PRIMARY KEY,skills text NOT NULL,titles text,message TEXT NOT NULL);",
    function (err, result) {
      if (err) {
        console.error(err);
        // return res.status(500).json({ status: false, error: "Database error" });
      }
      console.log("table created!");
    }
  );
});

app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, "public")));

app.post("/recomsubmit", async (req, res) => {
  try {
    const { skills, titles, message } = req.body;
    const sql =
      "INSERT INTO recommendations (skills, titles, message) VALUES (?, ?, ?)";
    const values = [skills, titles, message];

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
    console.log(error.message);
    res.status(501).json(error);
  }
});

app.get("/recommends", async (req, res) => {
  const sql = "SELECT * FROM recommendations ORDER BY id DESC";
  pool.query(sql, (err, results) => {
    if (err) {
      console.error(err);
      res.send("Error fetching submissions.");
    } else {
      res.status(200).json({ recommends: results });
    }
  });
});

app.delete("/deleterecommendations/:id", async (req, res) => {
  const submissionId = req.params.id;
  const sql = "DELETE FROM recommendations WHERE id = ?";

  pool.query(sql, [submissionId], (err, result) => {
    if (err) {
      console.error(err);
      res.send("Error deleting submission.");
    } else {
      console.log("Submission deleted successfully");
      res.status(200).json({ submissions: result });
    }
  });
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
