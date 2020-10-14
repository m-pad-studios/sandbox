import React from 'react';
import './components/App.css';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import Gallery from './components/Gallery';
import Home from "./components/Home";
import Mangas from "./components/Mangas";
import { NaviPanel } from "./components/NaviPanel";

class App extends React.Component {


render(){
  if(this.props.authState === "signedIn"){
  return (
<div className="stars">
      <Router>
      <NaviPanel />
      <div>
      <Switch>
              <Route exact path="/"  component={Home} />
              <Route path="/minigames" component={Mangas} />
              <Route exact path="/gallery" component={Gallery} />
              
      </Switch>
      </div>
      </Router>
      {/* <Footer>
      &copy; {new Date().getFullYear()} Copyright: <img alt="Avatar" className="avatar" src={imageName}/> M-PAD Studios <br></br> <span style={style}>Icon made by Becris from www.flaticon.com</span>
</Footer> */}
</div>
    );
  } else {
    return null;
  }
}
}
 
var style = {
fontSize: "10px" 
}
export default App;