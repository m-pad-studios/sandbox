import React from "react";
import { SignIn, SignOut, Greetings } from "aws-amplify-react";
import config from "../appsync";
import { CustomSignIn } from "../components/CustomSignIn";
import App from "../App";
import { Authenticator } from "aws-amplify-react";

class AppWithAuth extends React.Component {
  render() {
    return (
      <div>
        <Authenticator
          hide={[SignIn, SignOut, Greetings]}
          amplifyConfig={config}
        >
          <CustomSignIn />

          <App />
        </Authenticator>
      </div>
    );
  }
}

export default AppWithAuth;