import React from "react";


function Footer({ children }) {
    return (
        <div>
           
            <div style={style} className='stars'>
                { children }
            </div>
        </div>
    )
}

var style = {
  color: 'white',
    textAlign: "center",
    left: "0",
    bottom: "0",
    width: "100%",
    overflow: "hidden",
}

export default Footer