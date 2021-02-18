const express = require("express");
const app = express();
const PORT = 8080;

app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.set("view engine", "ejs");

app.get("/", (req, res) => {
    res.render("index", {data: "서버에서 넘겨준 데이터"});
});

app.listen(PORT, () => console.log(`this server listening on ${PORT}`));
