import React from "react";
import { css } from "glamor";
import { v4 as uuid } from "uuid";
import { graphql } from "react-apollo";
import CreateManga from "../mutations/CreateManga";
import ListMangas from "../queries/ListMangas";

console.log(uuid);

class AddManga extends React.Component {
  state = {
    name: "",
    content: "",
    contents: [],
    text: "",
    texts: [],
  };

  onChange = (key, value) => {
    this.setState({ [key]: value });
  };

  addContent = () => {
    if (this.state.content === "") return;
    const contents = this.state.contents;
    contents.push(this.state.content);
    this.setState({
      contents,
      content: "",
    });
  };

  addText = () => {
    if (this.state.text === "") return;
    const texts = this.state.texts;
    texts.push(this.state.text);
    this.setState({
      texts,
      text: "",
    });
  };

  addManga = () => {
    const { name, contents, texts } = this.state;
    this.props.onAdd({
      id: uuid(),
      contents,
      texts,
      name,
    });
    this.setState({
      name: "",
      content: "",
      contents: [],
      text: "",
      texts: [],
    });
  };

  render() {
    return (
      <div {...css(styles.container)} className="white">
        <h2>Enter a name for the new feature idea</h2>
        <input
          value={this.state.name}
          onChange={(evt) => this.onChange("name", evt.target.value)}
          placeholder="Feature name"
          {...css(styles.input)}
        />
        <div>
          <p>Description of feature:</p>
          {this.state.contents.map((content, i) => (
            <p key={i}>{content}</p>
          ))}
        </div>
        <input
          value={this.state.content}
          onChange={(evt) => this.onChange("content", evt.target.value)}
          placeholder="brief paragraph of what the idea is"
          {...css(styles.input)}
        />
        <div {...css(styles.submitButton)}>
          <button className="myButton" onClick={this.addContent}>
            Add text
          </button>
        </div>
        <div>
          <p>What will the new feature do: </p>
          {this.state.texts.map((text, i) => (
            <p key={i}>{text}</p>
          ))}
        </div>
        <input
          value={this.state.text}
          onChange={(evt) => this.onChange("text", evt.target.value)}
          placeholder="Bullet points on what the feature will do"
          {...css(styles.input)}
        />
        <div {...css(styles.submitButton)}>
          <button className="myButton" onClick={this.addText}>
            Add bullet point
          </button>
        </div>

        <div></div>

        <button className="myButton" onClick={this.addManga}>
          Add Note
        </button>
      </div>
    );
  }
}

export default graphql(CreateManga, {
  props: (props) => ({
    onAdd: (manga) =>
      props.mutate({
        variables: manga,
        optimisticResponse: {
          __typename: "Mutation",
          createManga: { ...manga, __typename: "Manga" },
        },
        update: (proxy, { data: { createManga } }) => {
          const data = proxy.readQuery({ query: ListMangas });
          data.listMangas.items.push(createManga);
          proxy.writeQuery({ query: ListMangas, data });
        },
      }),
  }),
})(AddManga);

const styles = {
  button: {
    border: "none",
    background: "rgba(0, 0, 0, .1)",
    width: 250,
    height: 50,
    cursor: "pointer",
    margin: "15px 0px",
  },
  container: {
    display: "flex",
    flexDirection: "column",
    paddingLeft: 100,
    paddingRight: 100,
    textAlign: "left",
    boxShadow: "2px 2px 5px rgba(0, 0, 0, .2)",
    marginBottom: 7,
    backgroundColor: "#212529",
    padding: 14,
    border: "1px solid #ededed",
    color: "white",
  },
  input: {
    outline: "none",
    border: "none",
    borderBottom: "2px solid black",
    height: "44px",
    fontSize: "18px",
  },
  textarea: {
    border: "1px solid #ddd",
    outline: "none",
    fontSize: "18px",
  },
  submitButton: {
    padding: "8px 30px",
    display: "flex",
    justifyContent: "center",
    alignItems: "center",
    cursor: "pointer",
    ":hover": {
      opacity: 1,
    },
  },
};
