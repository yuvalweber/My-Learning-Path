const express = require("express");
const bodyParser = require("body-parser");
const { darkcyan } = require("color-name");
const mongoose = require("mongoose");
const _ = require("lodash");

const app = express();

app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static("public"));

mongoose.connect("mongodb://mongo:27017/todolistDb", {useNewUrlParser: true});

const itemsSchema = new mongoose.Schema ({
    name: String
});

const Item = new mongoose.model("Item",itemsSchema);

//creating document for example

const food = new Item ({
    name: "Buy Food"
});

const cook = new Item ({
    name: "Cook Food"
});

const defaultItems =  [food,cook];

const listSchema = new mongoose.Schema ({
    name: String,
    items: [itemsSchema]
});

const List = mongoose.model("List",listSchema);



app.get("/",function(req,res) {
    Item.find({},function(err,results) {
        if(results.length === 0) {
            Item.insertMany(defaultItems,function(err) {
                if(err) {
                    console.log("Error!");
                }
                else {
                    console.log("Success!");
                }
            });
            res.redirect("/");
        }
        else {
        res.render("list",{Titling:"My To Do List",newListItems: results});
        }
    });
});

app.get("/:route",function(req,res) {
    const route_name = _.capitalize(req.params.route);
    List.findOne({name:route_name},function(err,results) {
            if(!results) {
                const list = new List ({
                    name: route_name,
                    items: defaultItems  
                  });

                  list.save();
                  res.redirect("/" + route_name);
                }
            else {
                res.render("list",{Titling:route_name,newListItems:results.items});
            }
    });
    
});

app.post("/", function(req,res) {
    const itemName = req.body.newItem;
    const Title = req.body.button;
    
    const newItem = new Item ({
        name: itemName
    });

    if(Title === "My To Do List"){
        newItem.save();
        res.redirect("/");
    }
    else {
        List.findOne({name:Title},function(err,results){
            results.items.push(newItem);
            results.save();
            res.redirect("/" + Title);
        })
    }
});

app.post("/delete",function(req,res) {
    const itemId = req.body.checkbox;
    const listName = req.body.listName;
    if(listName === "My To Do List") {
    Item.findByIdAndRemove(itemId,function(err) {
        if(err) {
            console.log("Failed to Remove item!");
        }
        else {
            console.log("Successfully remove the item");
            res.redirect("/");
        }
    
    });
    }
    else {
        List.findOneAndUpdate({name:listName},{$pull: {items:{_id: itemId} }},function(err){
            if(err) {
                console.log("Failed to remove item!");
            }
            else {
                console.log("Sucessfully remove item!");
                res.redirect("/" + listName);
            }
        })
    }
});

app.listen(80, function() {
console.log("server started and listen on port 80");
});