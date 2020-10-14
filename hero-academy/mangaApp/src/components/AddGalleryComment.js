import React from "react";
import { graphql } from "react-apollo";
import { v4 as uuid } from "uuid";
import CreateGalleryComment from "../mutations/CreateGalleryComment";
import ListComments from "../queries/ListGalleryComments";
import "./App.css";
import { Auth } from "aws-amplify";

let date = new Date();


let users = Promise.resolve(
  Auth.currentAuthenticatedUser({
    bypassCache: true, // Optional, By default is false. If set to true, this call will send a request to Cognito to get the latest user data
  }).then((user) => {
    user = user.username;
    console.log(user);
    return user;
  })
);

function u() {
  users.then((value) => {
    document.getElementById("user").value = value;
  });
}

function reload() {
  window.location.reload();
}

function alert() {
  document.getElementById("warning").innerHTML =
    "Can't submit an empty comment!";
  setTimeout(function () {
    document.getElementById("warning").innerHTML = "";
  }, 2000);
}

function getTime() {
  let date = new Date();
  

  document.getElementById("time").value = date;
}

function checkUser() {
  Auth.currentAuthenticatedUser({
    bypassCache: true, // Optional, By default is false. If set to true, this call will send a request to Cognito to get the latest user data
  })
    .then(
      (user) => (document.getElementById("checkuser").innerHTML = user.username)
    )
    .catch((err) => console.log(err));
}

class AddGalleryComment extends React.Component {
  state = {
    text: "",
    user: "",
    created: "",
  };

  onChange = (key, value) => {
    this.setState({ [key]: value });
  };

  addMyCustomType = () => {
    getTime();
    if (
      document.getElementById("user").value !=
      document.getElementById("checkuser").innerHTML
    ) {
      return reload();
    }
    if (document.getElementById("words").value === "") {
      return alert();
    }
    this.state.user = document.getElementById("user").value;
    this.state.created = document.getElementById("time").value;
    const { text, user, created } = this.state;
    this.props.onAdd({
      id: uuid(),
      text,
      user,
      created,
    });

    this.setState({
      text: "",
      user: "",
      created: "",
    });
  };

  render() {
    return (
      <div className="the-comments">
        <input
          id="words"
          className="textarea"
          value={this.state.text}
          onChange={(evt) => this.onChange("text", evt.target.value)}
          placeholder="leave a comment"
        />
        <br></br>
        <br></br>
        <input
          id="user"
          value={(this.state.user = u())}
          className="white"
          onChange={(evt) => this.onChange("user", evt.target.value)}
          disabled="true"
          hidden="true"
        />
        <input
          id="time"
          value={(this.state.created = date)}
          className="white"
          //onChange={(evt) => this.onChange("created", evt.target.value)}
          disabled="true"
          hidden="true"
        />
        <a className="myButton" onClick={this.addMyCustomType}>
          Add Comment
        </a>
        <hr></hr>
        <label
          id="checkuser"
          className="white"
          value={checkUser()}
          hidden="true"
        ></label>
        <div id="warning" className="warning-tag"></div>
      </div>
    );
  }
}

export default graphql(CreateGalleryComment, {
  props: (props) => ({
    onAdd: (comment) =>
      props.mutate({
        variables: comment,
        optimisticResponse: {
          __typename: "Mutation",
          createMyCustomType: { ...comment, __typename: "MyCustomType" },
        },
        update: (proxy, { data: { createMyCustomType } }) => {
          const data = proxy.readQuery({ query: ListComments });
          data.ListComments.items.push(createMyCustomType);
          proxy.writeQuery({ query: ListComments, data });
        },
      }),
  }),
})(AddGalleryComment);
