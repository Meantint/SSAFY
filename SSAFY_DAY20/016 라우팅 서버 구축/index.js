const express = require("express");
const app = express();

app.get("/", (req, res) => {
    try {
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/login", (req, res) => {
    try {
        return res.sendFile(__dirname + "/login.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/signup", (req, res) => {
    try {
        return res.sendFile(__dirname + "/signup.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.listen(8111, () => {
    console.log("this app listening on 8111 port");
});
