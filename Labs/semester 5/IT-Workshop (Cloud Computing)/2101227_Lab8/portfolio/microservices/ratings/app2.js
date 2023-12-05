const express = require("express");
const mysql = require("mysql2");
const bodyParser = require("body-parser");
const port = process.env.PORT || 5002;
const app = express();
const path = require("path");

const cors = require("cors");
app.use(cors());

const pool = mysql.createPool({
  // host: "localhost",
  host: "contactform.cfmfrfg6ylcp.ap-south-1.rds.amazonaws.com",
  // user: "root",
  user: "admin",
  password: "password",
  // database: "contactform",
  database:"ratings",
});



pool.getConnection(function (err, connection) {
  pool.query(
    "create table if not exists rating (id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(255) NOT NULL,email VARCHAR(255) NOT NULL, rate INT);",
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

app.post("/rate", async(req, res) => {
  try {
    const { name, email, rate } = req.body;
    console.log(name, email, rate);
    const sql = "INSERT INTO rating (name, email, rate) VALUES (?, ?, ?)";
    const values = [name, email, rate];

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


app.get("/getrating", async(req, res) => {
  const sql = "SELECT * FROM rating ORDER BY id DESC";
  pool.query(sql, (err, results) => {
    if (err) {
      console.error(err);
      res.send("Error fetching submissions.");
    } else {
      res.status(200).json({ getrating: results });
    }
  });
});

app.delete("/deleteratings/:id", async(req, res) => {
  const submissionId = req.params.id;
  const sql = "DELETE FROM rating WHERE id = ?";

  pool.query(sql, [submissionId], (err, result) => {
    if (err) {
      console.error(err);
      res.send("Error deleting submission.");
    } else {
      console.log("Submission deleted successfully");
      res.status(200).json({ getrating: result });
    }
  });
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});