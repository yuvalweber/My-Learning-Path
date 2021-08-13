//jshint esversion:6
const mongoose = require("mongoose");

// connect to instance and db
mongoose.connect("mongodb://localhost:27017/fruitsDB",{ useNewUrlParser: true});

// create schema for document you going to insert to the collection
const fruitSchema = new mongoose.Schema ({
    name: {
        type: String,
        required: [true,"name must be specified!"]
    },
    rating: {
        type: Number,
        min: 1,
        max: 10
    },
    review: String
});

//model to insert to the collection
const Fruit = mongoose.model("Fruit",fruitSchema);

//inserting info to the collection
const fruit = new Fruit ({
    name: "Apple",
    rating: 7,
    review: "Nice"
});

const bdika = new Fruit ({
    name: "Orange",
    rating: 8,
    review: "Very Good"
});

fruit.save();
bdika.save();

//
const personSchema = new mongoose.Schema ({
    name: String,
    email: String,
    favoriteFruit: fruitSchema
});

const Person = new mongoose.model("Person",personSchema);

//insert many
Fruit.insertMany([fruit,bdika], function(err){
    if(err){
        console.log("Error");
    }
    
});

// find something
Fruit.find(function(err,fruits) {
    if (err) {
        console.log("Error");
    }
    else {
        mongoose.connection.close();
        console.log(fruits);
    }
});

// update document
Fruit.updateOne({_id : 1},{name:"Dani"},function(err) {
    if(err) {
        console.log("Error");
    }
    else {
        console.log("Document Successfully Updated :)");
    }
});

// delete document
Fruit.deleteOne({_id: 1},function(err) {
    if(err) {
        console.log("Error");
    }
    else {
        console.log("Sucessfully deleted");
    }
});

