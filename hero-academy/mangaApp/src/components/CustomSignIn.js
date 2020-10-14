import React from "react";
import { SignIn } from "aws-amplify-react";


export class CustomSignIn extends SignIn {
  constructor(props) {
    super(props);
    this._validAuthStates = ["signIn", "signedOut", "signedUp"];
  }

  showComponent(theme) {
    return (
      <div className="starsLogin">
        <h1 className="whiteText">M-PAD Studios</h1>
        <form >
          <div className="mb-4">
            
            <input
              className="textarea"
              id="username"
              key="username"
              name="username"
              onChange={this.handleInputChange}
              type="text"
              placeholder="Username"
            />
          </div>
          <br></br>
          <div >
           
            <input
              className="textarea"
              id="password"
              key="password"
              name="password"
              onChange={this.handleInputChange}
              type="password"
              placeholder="Password"
            />
            <hr></hr>
            <p className="whiteText">
            <a
              className="myButton"
             
              onClick={() => super.signIn()}
            >
              Login
            </a>
            </p>
            <hr></hr>
            <p className="whiteText">
              Forgot your password?{" "}
              <a
                className="myButton"
                onClick={() => super.changeState("forgotPassword")}
              >
                Reset Password
              </a>
            </p>
          </div>
          <div >
            <hr></hr>
            <p className="whiteText">
              No Account?{" "}
              <a
                className="myButton"
                onClick={() => super.changeState("signUp")}
            >
          
                Create account
              </a>
            </p>
           
          </div>
        </form>
      </div>
    );
  }
}