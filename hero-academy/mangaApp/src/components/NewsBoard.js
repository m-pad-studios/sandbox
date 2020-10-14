import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";
import { graphql } from "react-apollo";
import NewMangaSubscription from "../subscriptions/NewMangaSubscription";
import ListMangas from "../queries/ListMangas";

console.log(uuid);

class NewsBoard extends React.Component {
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
    this.props.subscribeToNewMangas();
  }

  render() {
    return (
      <div className="news-board">
        <label
          className="title"
          onClick={(e) => this.togglePanel(e)}
          {...css(styles.breakLine)}
        >
          News Board
        </label>
        {this.state.open ? (
          <div className="content">
            {this.props.mangas.map((m, i) => (
              <div {...css(styles.manga)} key={i} className="white">
                <p {...css(styles.title)}>Feature: {m.name}</p>
                <div>
                  <p {...css(styles.title)}>Description: </p>
                  {m.contents.map((content, i2) => (
                    <p key={i2} {...css(styles.subtitle)}>
                      {content}
                    </p>
                  ))}
                </div>
                <div>
                  <p {...css(styles.title)}>Bullet points about feature: </p>
                  {m.texts.map((text, i3) => (
                    <p key={i3} {...css(styles.subtitle)}>
                      {i3 + 1}. {text}
                    </p>
                  ))}
                </div>
                <hr />
              </div>
            ))}
          </div>
        ) : null}
      </div>
    );
  }
}

export default graphql(ListMangas, {
  options: {
    fetchPolicy: "cache-and-network",
  },
  props: (props) => ({
    mangas: props.data.listMangas ? props.data.listMangas.items : [],
    subscribeToNewMangas: (params) => {
      props.data.subscribeToMore({
        document: NewMangaSubscription,
        updateQuery: (
          prev,
          {
            subscriptionData: {
              data: { onCreateManga },
            },
          }
        ) => {
          return {
            ...prev,
            listMangas: {
              __typename: "MangaConnection",
              items: [
                onCreateManga,
                ...prev.listMangas.items.filter(
                  (manga) => manga.id !== onCreateManga.id
                ),
              ],
            },
          };
        },
      });
    },
  }),
})(NewsBoard);

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
