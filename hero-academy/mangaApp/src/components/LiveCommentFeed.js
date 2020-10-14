import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";
import { graphql } from "react-apollo";
import NewMyCustomTypeSubscription from "../subscriptions/NewGalleryCommentSubscription";
import listMyCustomTypes from "../queries/ListGalleryComments";
import AddGalleryComment  from './AddGalleryComment';

console.log(uuid);

let date = new Date();
let time = date.toLocaleTimeString();

class LiveCommentFeed extends React.Component {
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
  
  componentDidMount() {
    this.props.subscribeToNewMyCustomTypes();
  }

  render() {
    return (
      <div className="news-board">
        <label
          className="title"
          onClick={(e) => this.togglePanel(e)}
          {...css(styles.breakLine)}
        >
          Live Comment Feed
        </label>
        {this.state.open ? (
           <div className="content">
          
           {this.props.comments.map((m, i) => (
             <p key={i} {...css(styles.h1)}>
               {m.text} <br></br> @{m.user} - {m.created}
             </p>
           ))}
           <hr {...css(styles.breakLine)}></hr>
           <AddGalleryComment />
         </div>
        ) : null}
      </div>
    );
  }
}

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
  })(LiveCommentFeed);
  

const styles = {
  title: {
    fontSize: "20px",
    color: "white",
  },
  subtitle: {
    fontSize: "20px",
    //color: 'black',
    fontWeight: "bold",
    color: "white",
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
    fontSize: "20px",
  },
  manga: {
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginBottom: 7,
    backgroundColor: "#212529",
    color: "white",
    padding: 14,
    border: "1px solid #ededed",
  },
  breakLine: {
    outline: "none",
    border: "none",
    borderBottom: "2px solid white",
    height: "44px",
    fontSize: "18px",
    color: "white",
  },
};
