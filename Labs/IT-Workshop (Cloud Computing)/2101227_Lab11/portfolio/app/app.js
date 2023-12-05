const express = require("express");
const session = require("express-session");
const passport = require("passport");
const auth = require("./auth");
const mysql = require("mysql2");
const bodyParser = require("body-parser");
const app = express();
const axios = require("axios");
const cors = require("cors");
app.use(cors());
const { Console } = require("console");
const port = process.env.PORT || 5000;
const path = require("path");

const url1 = process.env.service || "http://localhost:5001";
const url2 = process.env.service || "http://localhost:5002";
const url3 = process.env.service || "http://localhost:5003";

// const url = "https://jutlawbgwh.execute-api.ap-south-1.amazonaws.com/dev";

const APIcomment = axios.create({ baseURL: url1 });
const APIrating = axios.create({ baseURL: url2 });
const APIrecom = axios.create({ baseURL: url3 });

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, "public")));
app.set("view engine", "ejs");
app.use(bodyParser.json());

app.use(
  session({ name: "x", secret: "cats", resave: false, saveUninitialized: true })
);
app.use(passport.initialize());
app.use(passport.session());

app.get("/", async (req, res) => {
  res.render("index");
});

app.get("/dashboard", ensureAuthenticated, async (req, res) => {
  res.render("dashboard");
});

// app.get("/Login", (req, res) => {
//   res.render("login");
// });

// app.get("/Signup", (req, res) => {
//   res.render("signup");
// });

// ------------------------------------------------------

// function isLoggedIn(req, res, next) {
//   req.user ? next() : res.sendStatus(401);
// }

app.get(
  "/auth/google",
  passport.authenticate("google", {
    session: false,
    scope: ["profile", "email"],
    prompt: "select_account",
  })
);

app.get(
  "/auth/google/callback",
  passport.authenticate("google", { failureRedirect: "/auth/google/callback" }),
  (req, res) => {
    res.redirect("/dashboard");
  }
);

app.get("/auth/failure", (req, res) => {
  res.send("Authentication failed. Only @iiitg.ac.in domain is allowed.");
});

// function logo(req, res, next) {
//   req.logOut(function (err) {
//     if (err) {
//       return next(err);
//     }
//     // res.redirect("/");
//   });
// }

app.get("/logout", (req, res) => {
  req.logOut(function (err) {
    if (err) {
      return next(err);
    }
    res.redirect("/");
  });
});

function ensureAuthenticated(req, res, next) {
  if (req.isAuthenticated()) {
    return next();
  } else {
    res.redirect("/auth/google");
    // res.redirect("/");
  }
}

// ------------------------------------------------------
// --------------services1-------------------------------

app.post("/submit", ensureAuthenticated, async (req, res) => {
  const email = req.user.email;
  // console.log(req);
  const { name, message } = req.body;

  await APIcomment.post("submit", { name, email, message });
  res.redirect("/dashboard");
});

// app.post("/submit", ensureAuthenticated, async (req, res) => {
//   const { name, message } = req.body;
//   await APIcomment.post("submit", { name, email, message });
//   res.redirect("/");
// });

app.get("/deletesubmission/:id", ensureAuthenticated, async (req, res) => {
  const id = req.params.id;
  const results = await APIcomment.delete("/deletesubmission/" + id);
  res.redirect("/viewsubmissions");
});

app.get("/viewsubmissions", ensureAuthenticated, async (req, res) => {
  const results = await APIcomment.get("/submissions");
  console.log(results.data.submissions);
  res.render("submissions", { submissions: results.data.submissions });
});

// -----------------------------------------------------
// --------------services2------------------------------

app.post("/rate", ensureAuthenticated, async (req, res) => {
  const email = req.user.email;
  const { name, rate } = req.body;
  await APIrating.post("rate", { name, email, rate });
  res.redirect("/dashboard");
});

// app.post("/rate", ensureAuthenticated, async (req, res) => {
//   const { name, email, rate } = req.body;
//   await APIrating.post("rate", { name, email, rate });
//   res.redirect("/");
// });

app.get("/rate", ensureAuthenticated, async (req, res) => {
  res.render("rating");
});

app.get("/deleteratings/:id", ensureAuthenticated, async (req, res) => {
  const id = req.params.id;
  const results = await APIrating.delete("/deleteratings/" + id);
  res.redirect("/viewrating");
});

app.get("/viewrating", ensureAuthenticated, async (req, res) => {
  const results = await APIrating.get("/getrating");
  res.render("ratingsubmissions", { recommendations: results.data.getrating });
});

// -----------------------------------------------------
// ------------------services3--------------------------

app.post("/recomsubmit", ensureAuthenticated, async (req, res) => {
  const { skills, titles, message } = req.body;
  // console.log("hello");
  await APIrecom.post("/recomsubmit", { skills, titles, message });
  // console.log("Data inserted successfully");
  res.redirect("/dashboard");
});

// app.post("/recomsubmit", ensureAuthenticated, async (req, res) => {
//   const { skills, titles, message } = req.body;
//   console.log("hello");
//   await APIrecom.post("/recomsubmit", { skills, titles, message });
//   console.log("Data inserted successfully");
//   res.redirect("/");
// });

app.get("/viewrecommends", ensureAuthenticated, async (req, res) => {
  const results = await APIrecom.get("/recommends");
  res.render("suggestionssubmissions", {
    recommendations: results.data.recommends,
  });
});

app.get("/deleterecommendations/:id", ensureAuthenticated, async (req, res) => {
  const results = await APIrecom.delete(
    "/deleterecommendations/" + req.params.id
  );
  console.log(results);
  res.redirect("/viewrecommends");
});

app.get("/recommend", ensureAuthenticated, async (req, res) => {
  res.render("suggestions");
});

// -----------------------------------------------------

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
