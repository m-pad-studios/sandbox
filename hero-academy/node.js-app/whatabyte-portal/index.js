// index.js

/**
 * Required External Modules
 */

const express = require("express");
const path = require("path");
const sqlite3 = require("sqlite3").verbose();

/**
 * SQLite3 DB Setup
 */
const db_name = path.join(__dirname, "data", "heroes.db");
const db = new sqlite3.Database(db_name, err => {
  if(err) {
    return console.error(err.message);
  }
  console.log("Successful connection to the DB");
});

const sql_create = `CREATE TABLE IF NOT EXISTS heroes (
  Hero_ID INTEGER PRIMARY KEY AUTOINCREMENT,
  Name VARCHAR(100) NOT NULL,
  Hero_Title VARCHAR(100) NOT NULL,
  Power VARCHAR(100) NOT NULL,

)`;

/**
 * Express server setup
 */

const expressSession = require("express-session");
const passport = require("passport");
const Auth0Strategy = require("passport-auth0");

require("dotenv").config();

const authRouter = require("./auth");
/**
 * App Variables
 */
const app = express();
const port = process.env.PORT || "8000";

/**
 *  Session Configuration
 */

const session = {
  secret: "LoxodontaElephasMammuthusPalaeoloxodonPrimelephas",
  cookie: {},
  resave: false,
  saveUninitialized: false
};

if (app.get("env") === "production") {
  // Serve secure cookies, requires HTTPS
  session.cookie.secure = true;
}

 /**
  * Passport Configuration
  */
const strategy = new Auth0Strategy(
  {
    domain: process.env.AUTH0_DOMAIN,
    clientID: process.env.AUTH0_CLIENT_ID,
    clientSecret: process.env.AUTH0_CLIENT_SECRET,
    callbackURL:                         // replace with http://localhost:3000/callback
      process.env.AUTH0_CALLBACK_URL || " https://mpadstudios.herokuapp.com/callback"
  },
  function(accessToken, refreshToken, extraParams, profile, done) {
    return done(null, profile);
  }
)

/**
 *  App Configuration
 */
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "pug");
app.use(express.static(path.join(__dirname, "public")));

app.use(expressSession(session));

passport.use(strategy);
app.use(passport.initialize());
app.use(passport.session());

passport.serializeUser((user, done) => {
  done(null, user);
});

passport.deserializeUser((user, done) => {
  done(null, user);
});


// Creating custom middleware with Express
app.use((req, res, next) => {
  res.locals.isAuthenticated = req.isAuthenticated();
  next();
});


// Router mounting
app.use("/", authRouter);


/**
 * Routes Definitions
 */
const secured = (req, res, next) => {
  if (req.user) {
    return next();
  }
  req.session.returnTo = req.originalUrl;
  res.redirect("/login");
};

app.get("/", (req, res) => {
    res.render("index", { title: "Home" });
  });

  app.get("/create_hero", (req, res) => {
    res.render("create_hero", { title: "Hero" });
  });
  
app.get("/logout_page", (req, res, next) => {
  res.render("logout_page", { 
    title: "Logout Page"
  });
});

app.get("/user", secured, (req, res, next) => {
  const { _raw, _json, ...userProfile } = req.user;
  res.render("user", {
    title: "Profile",
    userProfile: userProfile
  });
});


/**
 * Server Activation
 */

app.listen(port, () => {
    console.log(`Listening to requests on ${port}`);
  });