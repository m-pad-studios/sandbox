import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";

import Grid from "@material-ui/core/Grid";
import { graphql } from "react-apollo";
import AddGalleryComment from "./AddGalleryComment";
import NewMyCustomTypeSubscription from "../subscriptions/NewGalleryCommentSubscription";
import listMyCustomTypes from "../queries/ListGalleryComments";

console.log(uuid);

var imageName = require("../images/rsz_trunks.jpg");
var broly = require("../images/broly.jpeg");
var dbz = require("../images/rsz_1dbz.png");

class Collapsible extends React.Component {
  componentDidMount() {
    this.props.subscribeToNewMyCustomTypes();
  }
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
        <div onClick={(e) => this.togglePanel(e)} {...css(styles.title)}>
          {this.props.title}
          <img src={dbz} alt="Avatar" />
        </div>
        {this.state.open ? (
          <div className="content">
            {this.props.children}

            <Grid container spacing={3} >
              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>Trunks!</h1>
                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>

                  <img
                    alt="Avatar"
                    className="avatar"
                    src={imageName}
                    {...css(styles.image)}
                  />
                  <hr></hr>

                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>

                  <hr></hr>

                  <hr></hr>
                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>
                </div>
              </Grid>

              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>Broly!</h1>
                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>
                  <img
                    alt="Avatar"
                    className="avatar"
                    src={broly}
                    {...css(styles.image)}
                  />
                  <hr></hr>
                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>

                  <hr></hr>

                  <hr></hr>
                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>
                </div>
              </Grid>
            </Grid>
          </div>
        ) : null}
      </div>
    );
  }
}

const styles = {
  gallery_images: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginBottom: 7,
    padding: 14,
    border: "1px solid #ededed",
    backgroundColor: "black",
    textAlign: "center",
  },
  h1: {
    textAlign: "center",
    fontSize: "25px",
    color: "white",
  },
  image: {
    height: "250px",
    width: "250px",
  },
  breakLine: {
    outline: "none",
    border: "none",
    borderBottom: "2px solid white",
    height: "44px",
    fontSize: "18px",
  },
  title: {
    textAlign: "center",
  },
};

export default graphql(listMyCustomTypes, {
  options: {
    fetchPolicy: "cache-and-network",
  },
  props: (props) => ({
    comments: props.data.listMyCustomTypes
      ? props.data.listMyCustomTypes.items
      : [],
    subscribeToNewMyCustomTypes: (params) => {
      props.data.subscribeToMore({
        document: NewMyCustomTypeSubscription,
        updateQuery: (
          prev,
          {
            subscriptionData: {
              data: { onCreateMyCustomType },
            },
          }
        ) => {
          return {
            ...prev,
            listMyCustomTypes: {
              __typename: "MyCustomTypesConnection",
              items: [
                onCreateMyCustomType,
                ...prev.listMyCustomTypes.items.filter(
                  (gallerycomment) =>
                    gallerycomment.id !== onCreateMyCustomType.id
                ),
              ],
            },
          };
        },
      });
    },
  }),
})(Collapsible);
