const express = require("express");
const app = express();

app.use((req, res, next) => {
    console.log("동작합니다");
    next();
});

const textMiddleware = (req, res, next) => {
    console.log("특정 부분에서만 동작합니다");
    // req.aa = "aa";
    next();
};

app.get("/", (req, res) => {
    try {
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.get("/hello", textMiddleware, (req, res) => {
    return res.json({ hello: "hello" });
});

app.listen(8100, () => console.log("this app listening on 8100 port"));
