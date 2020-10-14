import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";

import Grid from "@material-ui/core/Grid";
import { graphql } from "react-apollo";
import NewMyCustomTypeSubscription from "../subscriptions/NewGalleryCommentSubscription";
import listMyCustomTypes from "../queries/ListGalleryComments";


console.log(uuid);

var blocksImage = require("../images/atom.png");


var myGamePiece;
var bluePiece;
var yellowPiece;

function startGame() {
    myGamePiece = new component(30, 30, "blue", 8, 7);
    bluePiece = new component(20,20, "blue", 70, 50);
    yellowPiece = new component(10,10, "yellow", 100, 60);
    myGameArea.start();
}

var myGameArea = {
    canvas : document.createElement("canvas"),
    start : function() {
        this.canvas.width = 480;
        this.canvas.height = 270;
        this.canvas.backgroundColor = "white";
        this.context = this.canvas.getContext("2d");
        document.body.insertBefore(this.canvas, document.body.childNodes[0]);
        this.interval = setInterval(updateGameArea, 20);
        var blocks = document.getElementById("blocks");
        blocks.insertAdjacentElement("beforeend", this.canvas);      
    },
    stop : function() {
        clearInterval(this.interval);
    },    
    clear : function() {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
    }
}

function component(width, height, color, x, y, type) {
    this.type = type;
    this.width = width;
    this.height = height;
    this.x = x;
    this.y = y;    
    this.speedX = 0;
    this.speedY = 0.1;    
    this.gravity = 0.1;
    this.gravitySpeed = 10;
    this.bounce = 0.5;
    this.update = function() {
      var  ctx = myGameArea.context;
        ctx.fillStyle = color;
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
    this.newPos = function() {
        this.gravitySpeed += this.gravity;
        this.x += this.speedX;
        this.y += this.speedY + this.gravitySpeed;
        this.hitBottom();
    }
    this.hitBottom = function() {
        var rockbottom = myGameArea.canvas.height - this.height;
        if (this.y > rockbottom) {
            this.y = rockbottom;
            this.gravitySpeed = -(this.gravitySpeed * this.bounce);
        }
    }
}

function updateGameArea() {
    myGameArea.clear();
    myGamePiece.newPos();
    bluePiece.newPos();
    bluePiece.update();
    yellowPiece.update();
    yellowPiece.newPos();
    myGamePiece.update();
}

class Blocks extends React.Component {
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
          <img src={blocksImage} alt="Avatar" />
        </div>
        {this.state.open ? (
          <div className="content">
            {this.props.children}

            <Grid>
              <Grid item xs>
                <div {...css(styles.gallery_images)}>
                  <h1 {...css(styles.h1)}>Blocks!</h1>
                  <div {...css(styles.breakLine)}></div>
                  <hr></hr>
        <button onClick={() => startGame()}>Load some blocks</button>
        <div id="blocks"></div>
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
    backgroundColor: "#212529",
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
})(Blocks);
