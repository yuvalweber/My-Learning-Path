const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const mongoose = require("mongoose");

const app = express();

app.set("view engine","ejs");
app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static("public"));

mongoose.connect("mongodb://mongo:27017/wikiDB", {useNewUrlParser:true});

articlesSchema = new mongoose.Schema ({
   title: String,
   content: String 
});

Article = mongoose.model("article",articlesSchema);

const dom = new Article ({
    title: "daniel",
    content:"jacksonWill"
});

const danon = new Article ({
    title: "danon",
    content:"jacksonWillWer"
});

const drake = new Article ({
    title: "drake",
    content:"jacksonWillWerWe"
});

Article.insertMany([dom,danon,drake],function(err){
    if(err) {
        console.log("Failed!");
    }
    else {
        console.log("()-()");
    }
});

app.route("/articles")
.get(function(req,res) {
    Article.find({},function(err,foundArticles) {
        if(!err) {
            res.send(foundArticles);
        }
        else {
            res.send(err);
        }
    });
})
.post(function(req,res) {
    var item = new Article ({
        title: req.body.title,
        content: req.body.content
    });
    item.save(function(err) {
        if(err) {
            res.send("Failed!");
        }
        else {
            res.send("Success");
        }
    });
})
.delete(function(req,res) {
    Article.deleteMany({},function(err) {
        if(!err) {
            res.send("Deleted :)");
        }
        else {
            res.send("Failed to delete");
        }
    });
});

app.route("/articles/:topic")
.get(function(req,res) {
   Article.findOne({title:req.params.topic},function(err,result) {
       if(!err) {
           if(result) {
               res.send(result);
           }
           else {
               res.send("Not Found!");
           }
       }
   });
})
.put(function(req,res) {
    Article.update({title:req.params.topic},{title:req.body.title,content:req.body.content},{overwrite:true},function(err){
        if(err) {
            res.send("failed to update");
        }
        else {
            res.send("submitted successfully");
        }
    });
})
.patch(function(req,res) {
    Article.update({title: req.params.topic},{$set: req.body},function(err) {
        if(err) {
            res.send("Failed to Patch the article"); 
    }
    else {
        res.send("Success :)");
    }
});
})
.delete(function(req,res) {
    Article.deleteOne({title:req.params.topic},function(err) {
        if(err) {
            res.send("Failed");
        }
        else {
            res.send(":)");
        }
    });
});

app.listen(80, function() {
console.log("server started and listen on port 80");
});