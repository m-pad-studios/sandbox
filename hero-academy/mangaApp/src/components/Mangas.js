import React from "react";
import AddManga from "./AddManga";
import { css } from "glamor";
import TicTacToe from "./TicTacToe";
import Blocks from "./Blocks";

class Mangas extends React.Component {
  

  render() {
    return (
      <div {...css(styles.container)} className="starsManga">
        <h1 {...css(styles.h1)} className="white">
        {"Mini Games! "}
        </h1>
        <br></br>
        <div {...css(styles.gallery_greeting)}><TicTacToe /></div>
        <br></br>
        <div {...css(styles.gallery_greeting)}><Blocks /></div>
      </div>
    );
  }
}

const styles = {
  title: {
    fontSize: 25,
    color: "white",
  },
  subtitle: {
    fontSize: 14,
    //color: 'black',
    fontWeight: "bold",
    color: "white",
  },
  gallery_greeting: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginTop: 25,
    backgroundColor: "#212529",
    border: "1px solid white",
    textAlign: "left",
    color: "white",
   
   marginBottom: 10,
  },
  h1: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginBottom: 7,
    marginTop: 10,
    backgroundColor: "#212529",
    padding: 14,
    border: "1px solid #ededed",
    textAlign: "center",
    color: "white",
  },
  manga: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginBottom: 7,
    backgroundColor: "#212529",
    color: "white",
    padding: 14,
    border: "1px solid #ededed",
  },
  container: {
    display: "flex",
    flexDirection: "column",
   paddingLeft: 250,
    paddingRight: 250,
    textAlign: "center",
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    height: "100vh",
    color: "white",
  },
};

export default Mangas;
