import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";
import Grid from "@material-ui/core/Grid";
import { graphql } from "react-apollo";

import NewMyCustomTypeSubscription from "../subscriptions/NewGalleryCommentSubscription";
import listMyCustomTypes from "../queries/ListGalleryComments";

console.log(uuid);

var dio = require("../images/dio.png");
var jotaro = require("../images/jotaro.png");
var jojo = require("../images/rsz_1jojo.png");
var joestar = require("../images/joestar.jpeg");
var jota = require("../images/jota.jpeg");
var gio = require("../images/gio.jpeg");

class CollapseJoJo extends React.Component {
  componentDidMount() {
    this.props.subscribeToNewMyCustomTypes();
  }
  constructor(props) {
    super(props);

    this.state = {
      open: false,
    };
  }

  togglePanel(e) {
    this.setState({ open: !this.state.open });
  }

  render() {
    return (
      <div>
        <div className="jojo"></div>
        <hr></hr>

        <div onClick={(e) => this.togglePanel(e)} {...css(styles.title)}>
          {this.props.title} <img src={jojo} alt="Avatar" />
        </div>
        {this.state.open ? (
          <div className="content">
            {this.props.children}

            <Grid container spacing={3} >
              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>Dio!</h1>
                  <hr></hr>
                  <img
                    alt="Avatar"
                    className="avatar"
                    src={dio}
                    {...css(styles.image)}
                  />
                  <hr></hr>

                  <hr></hr>

                  <hr></hr>
                </div>
              </Grid>

              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>JoeStar!</h1>
                  <hr></hr>
                  <img
                    alt="Avatar"
                    className="avatar"
                    src={joestar}
                    {...css(styles.image)}
                  />
                  <hr></hr>

                  <hr></hr>

                  <hr></hr>
                </div>
              </Grid>
              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>Giorno!</h1>
                  <hr></hr>
                  <img
                    alt="Avatar"
                    className="avatar"
                    src={gio}
                    {...css(styles.image)}
                  />
                  <hr></hr>

                  <hr></hr>

                  <hr></hr>
                </div>
              </Grid>
              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>Jotaro & Star Platinum!</h1>
                  <hr></hr>
                  <img
                    alt="Avatar"
                    className="avatar"
                    src={jota}
                    {...css(styles.image)}
                  />
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
    backgroundColor: "black",
    padding: 14,
    border: "1px solid #ededed",
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
})(CollapseJoJo);