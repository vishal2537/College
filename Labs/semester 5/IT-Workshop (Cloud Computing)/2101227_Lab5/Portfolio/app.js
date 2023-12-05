const express = require("express");
const mysql = require("mysql2");
const bodyParser = require("body-parser");
const app = express();
const port = 3000;

const pool = mysql.createPool({
  host: "localhost",
  user: "root",
  password: "password",
  database: "contactform",
});


pool.getConnection(function (err, connection) {
  pool.query(
    "create table if not exists contacts (id INT AUTO_INCREMENT PRIMARY KEY,name VARCHAR(255) NOT NULL,email VARCHAR(255) NOT NULL,message TEXT NOT NULL);",
    function (err, result) {
      if (err) {
        console.error(err);
        return res.status(500).json({ status: false, error: "Database error" });
      }
      console.log("table created!");
    }
  );
});

app.set("view engine", "ejs");

// Use bodyParser to parse form data
app.use(bodyParser.urlencoded({ extended: true }));

// Serve static files (CSS, images, etc.)
app.use(express.static("public"));

// Define a route to render the contact form
app.get("/", (req, res) => {
  res.render("index");
});

// Handle form submissions
app.post("/submit", (req, res) => {
  const { name, email, message } = req.body;
  const sql = "INSERT INTO contacts (name, email, message) VALUES (?, ?, ?)";
  const values = [name, email, message];

  pool.query(sql, values, (err, result) => {
    if (err) {
      console.error(err);
      res.send("Error submitting the form.");
    } else {
      console.log("Form submitted successfully");
      //   res.send("Form submitted successfully");
      res.redirect("/");
    }
  });
});



app.get("/submissions", (req, res) => {
  const sql = "SELECT * FROM contacts ORDER BY id DESC";
  pool.query(sql, (err, results) => {
    if (err) {
      console.error(err);
      res.send("Error fetching submissions.");
    } else {
      // Render a page to display the submissions
      res.render("submissions", { submissions: results });
    }
  });
});

app.get("/delete-submission/:id", (req, res) => {
  const submissionId = req.params.id;
  const sql = "DELETE FROM contacts WHERE id = ?";

  pool.query(sql, [submissionId], (err, result) => {
    if (err) {
      console.error(err);
      res.send("Error deleting submission.");
    } else {
      console.log("Submission deleted successfully");
      // Redirect back to the submissions page
      res.redirect("/view-submissions");
    }
  });
});

app.get("/view-submissions", (req, res) => {
  res.redirect("/submissions");
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
