const express = require("express");
const bodyParser = require("body-parser");
const https = require("https");

const app = express();
app.use(bodyParser.urlencoded({extended:true}));

app.get("/",function(req,res) {
    res.sendFile(__dirname + "/index.html");
    https.get("https://www.google.com",function(response) {
        response.on("data", function(data) {
            var x = JSON.parse(data);
            var y = JSON.stringify(data);
            res.write(x);
            res.write(y);
            res.send();
        })
    });
    
})

app.post("/", function(req,res) {
    var query = req.body.CityName;
})

app.listen(80, function() {
    console.log("server up and running");
})