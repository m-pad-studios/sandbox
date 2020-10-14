// index.js

/**
 * Required External Modules
 */

const express = require("express");
const path = require("path");
const bodyParser = require('body-parser');
const db = require("./sqlite_db");

// create application/json parser
const jsonParser = bodyParser.json();

/**
 * Express server setup
 */

const expressSession = require("express-session");


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
 *  App Configuration
 */
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");
app.use(express.static(path.join(__dirname, "public")));
app.use(bodyParser.urlencoded({ extended: false }))

app.use(jsonParser);
app.use(expressSession(session));



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


app.get("/", (req, res) => {
    
    res.render("index", { title: "Home" });
  });

 

  app.get("/space_jelly_lab", (req, res) => {
    res.render("space_jelly_lab", { title: "Space Jelly Lab"});
  });

  app.get("/user_dash", (req, res) => {

  res.render("user_dash", { model: { }  });
   
   
  });

  app.get("/academy", (req, res) => {
    const sql = "SELECT * FROM SpaceCadets ORDER BY Title"
    db.all(sql, [], (err, rows) => {
      if (err) {
        return console.error(err.message);
      }
      res.render("academy", { model: rows });
    });
    
  });
  
app.get("/user", (req, res) => {
const sql = "SELECT * FROM SpaceCadets WHERE Space_ID = ?";

db.all(sql,[], (err, rows) => {
  if(err) {
    return console.error(err.message);
  }
  res.render("user", { model:  rows  });
}); 

});

app.post("/user", (req, res) => {
  
  const sql = "SELECT * FROM SpaceCadets WHERE Space_ID = ?";
  const spaceId = [req.body.Space_ID];
  
db.all(sql, [spaceId],(err, rows) => {
  if(err) {
    return console.error(err.message);
  }
   console.log(rows ? console.log(rows.Space_ID, rows.Name, rows.Title) : console.log('No Space Cadet by that ID exists'));
res.render("user", {model: rows});

});

});

  app.get("/life_line", (req, res) => {
    res.render("life_line", { title: "Home" });
  });

  app.get("/energy_field", (req, res) => {
    res.render("energy_field", { title: "About" });
  });
  

  app.get("/space_globe", (req, res) => {
    res.render("space_globe", { title: "About" });
  });

app.get("/create_cadet", (req, res) => {
  
  res.render("create_cadet", { model: {} });
});

app.post("/create", (req, res) => {
  const sql = "INSERT INTO SpaceCadets (Name, Title, Blood, Oxygen, Hunger, Jellies) VALUES ('Space Cadet', ?, 100, 100, 'F', 0)";
  const cadet = [req.body.Name];

  db.run(sql, cadet, err => {
    if(err) {
      console.error(err.message);
    }
    res.redirect("/academy");
  });
});

app.get("/create_space_leader", (req, res) => {
  
  res.render("create_space_leader", { model: {} });
});

app.post("/create_space_leader", (req, res) => {
  console.log("inside correct post");
  const sql = "INSERT INTO SpaceCadets (Title, Name, Blood, Oxygen, Hunger, Jellies) VALUES (? , ?, 100, 100, 'F', 0)";
  const cadet = [req.body.Name, req.body.Title];

  db.run(sql, cadet, err => {
    if(err) {
      console.error(err.message);
    }
    res.redirect("/academy");
  });
});

/**
 * Server Activation
 */

app.listen(port, () => {
  console.log(`Listening to requests on ${port}`);
});
