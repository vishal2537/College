const express = require("express");
const mysql = require("mysql2");
const bodyParser = require("body-parser");
const app = express();
const axios = require("axios");
const cors = require("cors");
app.use(cors());
const { Console } = require("console");
const port = process.env.PORT || 80;
const path = require("path");

// const pool = mysql.createPool({
//   // host: "localhost",
//   host: "contactform.cfmfrfg6ylcp.ap-south-1.rds.amazonaws.com",
//   // user: "root",
//   user: "admin",
//   password: "password",
//   database: "contactform",
// });

// const url1 = process.env.service || "http://localhost:5001";
// const url2 = process.env.service || "http://localhost:5002";
// const url3 = process.env.service || "http://localhost:5003";

// const url = "https://ye5o3aa9yf.execute-api.ap-south-1.amazonaws.com/dev";

const url = "https://jutlawbgwh.execute-api.ap-south-1.amazonaws.com/dev";

const APIcomment = axios.create({ baseURL: url });
const APIrating = axios.create({ baseURL: url });
const APIrecom = axios.create({ baseURL: url });

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, "public")));
app.set("view engine", "ejs");
app.use(bodyParser.json());

app.get("/", async (req, res) => {
  res.render("index");
});

// --------------services1-------------------------------

app.post("/submit", async (req, res) => {
  const { name, email, message } = req.body;
  await APIcomment.post("submit", { name, email, message });
  res.redirect("/");
});

app.get("/deletesubmission/:id", async (req, res) => {
  const id = req.params.id;
  const results = await APIcomment.delete("/deletesubmission/" + id);
  res.redirect("/viewsubmissions");
});

app.get("/viewsubmissions", async (req, res) => {
  const results = await APIcomment.get("/submissions");
  console.log(results.data.submissions);
  res.render("submissions", { submissions: results.data.submissions });
});

// -----------------------------------------------------
// --------------services2------------------------------

app.post("/rate", async (req, res) => {
  const { name, email, rate } = req.body;
  await APIrating.post("rate", { name, email, rate });
  res.redirect("/");
});

app.get("/rate", async (req, res) => {
  res.render("rating");
});

app.get("/deleteratings/:id", async (req, res) => {
  const id = req.params.id;
  const results = await APIrating.delete("/deleteratings/" + id);
  res.redirect("/viewrating");
});

app.get("/viewrating", async (req, res) => {
  const results = await APIrating.get("/getrating");
  res.render("ratingsubmissions", { recommendations: results.data.getrating });
});

// -----------------------------------------------------
// ------------------services3--------------------------

app.post("/recomsubmit", async (req, res) => {
  const { skills, titles, message } = req.body;
  console.log("hello");
  await APIrecom.post("/recomsubmit", { skills, titles, message });
  console.log("Data inserted successfully");
  res.redirect("/");
});

app.get("/viewrecommends", async (req, res) => {
  const results = await APIrecom.get("/recommends");
  res.render("suggestionssubmissions", {
    recommendations: results.data.recommends,
  });
});

app.get("/deleterecommendations/:id", async (req, res) => {
  const results = await APIrecom.delete(
    "/deleterecommendations/" + req.params.id
  );
  console.log(results);
  res.redirect("/viewrecommends");
});

app.get("/recommend", async (req, res) => {
  res.render("suggestions");
});

// -----------------------------------------------------

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
