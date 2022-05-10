import React, { useState } from "react";


const From = () => {
    const [fullName,setFullName] = useState({
        fname: "",
        lname: ""
    });

    const handleChange = ev => {
        const {value,name} = ev.target;
        setFullName(prevValue =>({...prevValue,[name]:value}))
    }

    return 
    (
    <>
    <h1> Hey {fullName.fname} {fullName.lname}</h1>
    <form>
        <input type="text" name="fname" onChange={handleChange}/>
        <input type="text" name="lname" onChange={handleChange}/>
    </form>
    </>
    )
}

export default Form;