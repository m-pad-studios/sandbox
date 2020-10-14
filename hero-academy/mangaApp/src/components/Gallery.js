import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";
import Collapsible from "./Collapsible";
import CollapseJoJo from "./CollapseJoJo";
import { graphql } from 'react-apollo';
import NewMyCustomTypeSubscription from '../subscriptions/NewGalleryCommentSubscription';
import listMyCustomTypes from '../queries/ListGalleryComments';
import CollapseOnePunchMan from "./CollapseOnePunchMan";


console.log(uuid);


class Gallery extends React.Component {
  render() {
    return (
      <div {...css(styles.container)} className="stars">
  
        <div {...css(styles.gallery_greeting)}>
          <p>
            <h1>Zach's Gallery</h1>
            Welcome to the Gallery!
            <br></br>This is an original gallery designed to showcase
            Zachariah's hand drawn anime! <br></br>
            This gallery is designed to showcase each drawing in their own
            'frame'. Click each logo to load the images & comments!
          </p>
          
        </div>
        <div {...css(styles.gallery_greeting)}>
          <Collapsible />
        </div>
        <br></br>
        <div {...css(styles.gallery_greeting)}>
          <CollapseJoJo />
        </div>
        <br></br>
        <div {...css(styles.gallery_greeting)}>
          <CollapseOnePunchMan />
        </div>    
      </div>
    );
  }
}


const styles = {
  container: {
    display: "flex",
    flexDirection: "column",
   
    paddingRight: 250,
    textAlign: "center",
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    height: "100vh",
    color: "white",
  },

  h1: {
    textAlign: "center",
    fontSize: "25px",
    color: "white",
  },
  breakLine: {
          
    outline: 'none',
    border: 'none',
    borderBottom: '2px solid white',
    height: '44px',
    fontSize: '18px',
  
},
  title: {
    textAlign: "center",
  },
  gallery_greeting: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginTop: 25,
    backgroundColor: "#212529",
    border: "1px solid white",
    textAlign: "center",
    color: "white",
   marginLeft: 250,
   marginBottom: 10,
  },
  comments: {


  },
  liveComments: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginTop: 25,
    backgroundColor: "#212529",
    border: "1px solid white",
    textAlign: "center",
    color: "white",
   marginLeft: 1150,
   marginBottom: 10,
   overflowWrap: 'anywhere',
  }
};

export default graphql(listMyCustomTypes, {
  options: {
    fetchPolicy: 'cache-and-network'
  },
  props: props => ({
    comments: props.data.listMyCustomTypes ? props.data.listMyCustomTypes.items : [],
    subscribeToNewMyCustomTypes: params => {
      props.data.subscribeToMore({
        document: NewMyCustomTypeSubscription,
        updateQuery: (prev, { subscriptionData: { data : { onCreateMyCustomType } } }) => {
          return {
            ...prev,
            listMyCustomTypes: {
              __typename: 'MyCustomTypesConnection',
              items: [onCreateMyCustomType, ...prev.listMyCustomTypes.items.filter(gallerycomment => gallerycomment.id !== onCreateMyCustomType.id)]
            }
          }
        }
      })
    }
  })
})(Gallery);