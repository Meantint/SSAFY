const express = require("express");
const app = express();

app.use((req, res, next) => {
    req.a = 30;
    next();
});

const otherMiddleware = (req, res, next) => {
    req.b = 15;
    next();
};

app.get("/", (req, res) => {
    try {
        console.log("a = " + req.a);
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/add", (req, res) => {
    try {
        console.log("a + a = " + Number(req.a + req.a));
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/sub", (req, res) => {
    try {
        console.log("a - 1 = " + Number(req.a - 1));
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/multi", (req, res) => {
    try {
        console.log("a * a = " + Number(req.a * req.a));
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/other", otherMiddleware, (req, res) => {
    try {
        console.log("a + b = " + Number(req.a + req.b));
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.listen(8100, () => console.log("this app listening on 8100 port"));
