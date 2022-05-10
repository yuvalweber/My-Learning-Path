import React, {useState} from 'react';
import './style.css'
import Card from './Components/Card'
import sampleCards from './samples'



const App = () => {
  const [name,setName] = useState("yuval");
  const changeName = newName => {
    setName(newName);
  }
    return (
    <div>
      <p className='testingCss'>this is example by: {name}</p>
      <p style={{color: "red"}}>this is red</p>
      {sampleCards.map((sampleCard) => {
        <Card 
        key= {sampleCard.id}
        Head= {sampleCard.Head}
        p1= {sampleCard.p1}
        p2= {sampleCard.p2}
        />
      })}
    </div>
    )
}

export default App;