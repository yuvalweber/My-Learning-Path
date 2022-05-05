import React from 'react';

const Card = (props) => {
    return (
        <div>
            <h2>{props.Head}</h2>
            <p>{props.p1}</p>
            <p>{props.p2}</p>
        </div>
    )
}

export default Card;