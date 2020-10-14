const sqlite3 = require("sqlite3").verbose();
const path = require("path");

/**
 * SQLite3 DB Setup
 */
const db_name = path.join(__dirname, "data", "mustacheo_inds.db");
const db = new sqlite3.Database(db_name, err => {
  if(err) {
    return console.error(err.message);
  }
  console.log("Successful connection to the DB");
  console.log("|||" + db_name + " |||");
});





// const sql_insert = `CREATE TABLE IF NOT EXISTS SpaceCadets (
//   Space_ID INTEGER PRIMARY KEY AUTOINCREMENT,
//   Title VARCHAR(100) NOT NULL,
//   Name VARCHAR(100) NOT NULL,
//   Blood INTEGER NOT NULL,
//   Oxygen INTEGER NOT NULL,
//   Hunger VARCHAR(1) NOT NULL,
//   Jellies INTEGER NOT NULL

// );`;




// const sql_insert_to_table = `INSERT INTO SpaceCadets (Title, Name, Blood, Oxygen, Hunger, Jellies) VALUES
// ('Mustacheo', 'Le Captain', 100, 100, 'F', 100),
//  ('T-Baby','General',56, 45, 'T', 89),
//  ('Troyus','Admiral', 100, 100, 'F', 69);`;



// console.log(db.run(sql_insert, err => {
//   if (err) {
//     return console.error(err.message);
//   }
//   console.log(sql_insert);
// }));


// console.log(db.run(sql_insert_to_table, err => {
//   if (err) {
//     return console.error(err.message);
//   }
//   console.log(sql_insert_to_table);
// }));

module.exports = db;