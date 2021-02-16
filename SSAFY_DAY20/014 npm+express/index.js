// express 사용 준비
const express = require("express");
const app = express();

app.get("/", (req, res) => {
    // console.log(__dirname);
    try {
        return res.sendFile(__dirname + "/index.html");
    } catch (err) {
        return res.send("404 NOT FOUND");
    }
});

app.listen(8100, () => {
    console.log("this app listening on 8100 port");
});
