const express = require("express");
const app = express();
const PORT = 8080;

app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.set("view engine", "ejs");

app.get("/", (req, res) => {
    res.render("index", { data: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] });
});

app.listen(PORT, () => console.log(`this server listening on ${PORT}`));
