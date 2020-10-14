import React from "react";
import { SignUp } from "aws-amplify-react";


export class CustomSignUp extends SignUp {
    constructor(props) {
        super(props);
        this._validAuthStates = ["signedUp"];
      }

      showComponent(theme) {
          return(
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
              Create Account
            </a>
            </p>
            </div>
            </form>
            
            </div>
            
          ); 
      }
}
