import React from 'react';
import  ReactDOM  from 'react';
import './style.css'

const name = "yuval";

ReactDOM.render(<div>
    <p className='testingCss'>this is example by: {name}</p>
    <p style={{color: "red"}}>this is red</p>
</div>,document.getElementById("root"));