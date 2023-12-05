const passport = require("passport");
const GoogleStrategy = require("passport-google-oauth2").Strategy;

const GOOGLE_CLIENT_ID =
  "768278090472-383uhl3qthspkeq3l9begket1dt693m6.apps.googleusercontent.com";
const GOOGLE_CLIENT_SECRET = "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";

passport.use(
  new GoogleStrategy(
    {
      clientID: GOOGLE_CLIENT_ID,
      clientSecret: GOOGLE_CLIENT_SECRET,
      callbackURL: "http://localhost:5000/auth/google/callback",
      passReqToCallback: true,
    },
    function (request, accessToken, refreshToken, profile, done) {
      const email =
        profile.emails && profile.emails.length > 0
          ? profile.emails[0].value
          : null;
      if (email && email.endsWith("iiitg.ac.in")) {
        return done(null, profile);
      } else {
        return done(null, false, { message: "Invalid email domain" });
      }
    }
  )
);

passport.serializeUser(function (user, done) {
  done(null, user);
});

passport.deserializeUser(function (user, done) {
  done(null, user);
});
