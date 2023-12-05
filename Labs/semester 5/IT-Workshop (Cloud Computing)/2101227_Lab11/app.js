const express = require("express");
const session = require("express-session");
const passport = require("passport");
const GoogleStrategy = require("passport-google-oauth20").Strategy;

const app = express();

// Configure session middleware
app.use(
  session({ secret: "your_secret_key", resave: true, saveUninitialized: true })
);

// Configure Passport to use Google OAuth 2.0
passport.use(
  new GoogleStrategy(
    {
      clientID: "YOUR_CLIENT_ID",
      clientSecret: "YOUR_CLIENT_SECRET",
      callbackURL: "http://localhost:3000/auth/google/callback",
    },
    (accessToken, refreshToken, profile, done) => {
      // Check if the user's email is from @iiitg.ac.in domain
      if (profile.emails && profile.emails.length > 0) {
        const userEmail = profile.emails[0].value;
        if (userEmail.endsWith("@iiitg.ac.in")) {
          return done(null, profile);
        }
      }
      return done(null, false);
    }
  )
);

// Serialize user into the session
passport.serializeUser((user, done) => {
  done(null, user);
});

// Deserialize user from the session
passport.deserializeUser((user, done) => {
  done(null, user);
});

// Initialize Passport
app.use(passport.initialize());
app.use(passport.session());

// Define authentication routes
app.get(
  "/auth/google",
  passport.authenticate("google", { scope: ["profile", "email"] })
);

app.get(
  "/auth/google/callback",
  passport.authenticate("google", {
    successRedirect: "/dashboard",
    failureRedirect: "/",
  })
);

// Route for authenticated users to post comments
app.get("/dashboard", (req, res) => {
  if (req.isAuthenticated()) {
    res.send("Welcome to the dashboard! You can post comments here.");
  } else {
    res.redirect("/");
  }
});

// Route for logging out
app.get("/logout", (req, res) => {
  req.logout();
  res.redirect("/");
});

// Home page
app.get("/", (req, res) => {
  res.send("Welcome to the home page. Please log in with your IIITG account.");
});

// Start the server
app.listen(3000, () => {
  console.log("Server started on http://localhost:3000");
});


// npm init
// npm install express express-session passport passport-google-oauth20
