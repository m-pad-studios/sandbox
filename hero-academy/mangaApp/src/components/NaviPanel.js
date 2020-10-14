import React from "react";
import { css } from "glamor";
import "./App.css";
import JSignOut from "./JSignOut";
import { Link } from "react-router-dom";
import { Nav } from "react-bootstrap/";

let avatar = require("../images/platinum_grin.jpg");

export class NaviPanel extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      open: false,
    };

    this.togglePanel = this.togglePanel.bind(this);
  }

  togglePanel(e) {
    this.setState({ open: !this.state.open });
  }
  render() {
    return (
      <div>
        <img alt="Avatar" src={avatar} {...css(styles.image)} />
        <label
          className="title"
          onClick={(e) => this.togglePanel(e)}
          {...css(styles.breakLine)}
        >
          Navi Panel
        </label>
        {this.state.open ? (
          <div>
            <label {...css(styles.naviPanelBox)}>
              <label {...css(styles.signOut)}>
                <Nav.Link as={Link} to="/">
                  Home!
                </Nav.Link>
              </label>
              <label {...css(styles.signOut)}>
                <Nav.Link as={Link} to="/gallery">
                  Gallery!
                </Nav.Link>
              </label>
              <label {...css(styles.signOut)}>
                <Nav.Link as={Link} to="/minigames">
                  MiniGames!
                </Nav.Link>
              </label>
              <label {...css(styles.navButtons)}>
                <JSignOut />
              </label>
            </label>
          </div>
        ) : null}
      </div>
    );
  }
}

const styles = {
  signOut: {
    marginLeft: "15px",
    marginTop: "10px",
    backgroundColor: "#212529",
    color: "white",
    border: "1px solid #ededed",
    width: "125px",
    height: "40px",
    borderRadius: "10",
  },
  navButtons: {
    marginLeft: "15px",
    marginTop: "10px",

    backgroundColor: "#212529",
    color: "white",
    border: "1px solid #ededed",
    width: "125px",
    height: "30px",
    borderRadius: "10",
  },
  breakLine: {
    outline: "none",
    border: "none",
    borderBottom: "2px solid white",
    height: "44px",
    fontSize: "18px",
    color: "white",
  },

  naviPanelBox: {
    marginTop: "-10px",
    marginLeft: "30px",

    color: "white",
    width: "125px",
    height: "125px",
    textAlign: "center",
    marginBottom: "100px",
  },
  image: {
    height: "50px",
    width: "50px",
    borderRadius: "150",
    marginRight: "15px",
  },
};
