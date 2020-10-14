import React, { Component } from "react";
import { Button } from "bootstrap-4-react";
import { Link } from "react-router-dom";
import { Auth } from "aws-amplify";
import { css } from "glamor";

export default class JSignOut extends Component {
  constructor(props) {
    super(props);
    this.signOut = this.signOut.bind(this);
  }

  signOut() {
    Auth.signOut({ global: true });
  }

  render() {
    return (
      <Link {...css(styles.link)} onClick={this.signOut}>
        Sign Out
      </Link>
    );
  }
}

const styles = {
  link: {
    textDecoration: "none",

    ":hover": {
      textDecoration: "underline",
    },
  },
  container: {
    overflow: "hidden",
  },
  heading: {
    color: "white",
    paddingRight: 20,
  },
};
