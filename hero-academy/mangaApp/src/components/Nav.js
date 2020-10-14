import React from 'react';
import { Link } from 'react-router-dom';
import JSignout from './JSignOut';
import {Nav, Navbar, NavDropdown} from 'react-bootstrap/';


export default class Navie extends React.Component {
  
    render() {
        return(
            <div >
       <Navbar collapseOnSelect expand="lg" bg="dark" variant="dark">
  <Navbar.Brand href="/">M-PAD Studios</Navbar.Brand>
  <Navbar.Toggle aria-controls="responsive-navbar-nav" />
  <Navbar.Collapse id="responsive-navbar-nav">
    <Nav className="mr-auto">
  
      <NavDropdown title="Logout" id="collasible-nav-dropdown">
      <NavDropdown.Item as={Link} to="/mangas">Notes to Leave Mikail</NavDropdown.Item>
      <NavDropdown.Item as={Link} to="/gallery">Gallery!</NavDropdown.Item>
     
        <NavDropdown.Divider />
        <NavDropdown.Item ><JSignout /></NavDropdown.Item>
      </NavDropdown>
     
    </Nav>
  
  </Navbar.Collapse>
</Navbar>
  </div>
        )
    }
}

