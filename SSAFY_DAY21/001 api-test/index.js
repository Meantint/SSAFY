const express = require("express");
const morgan = require("morgan");
const dotenv = require("dotenv");
const app = express();
const port = 8022;

dotenv.config();
app.use(morgan("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.get("/", (req, res) => {
    console.log(process.env.TEST);
    console.log(req.query);
    return res.json({ type: "get" });
});

app.get("/:id", (req, res) => {
    console.log(req.params);
    console.log(req.query);
    return res.json({ type: "get", params: req.params });
});

app.post("/", (req, res) => {
    console.log(req.params);
    console.log(req.query);
    console.log(req.body);
    return res.json({ type: "post" });
});

app.patch("/", (req, res) => {
    console.log(req.body);
    return res.json({ type: "patch" });
});

app.put("/", (req, res) => {
    console.log(req.body);
    return res.json({ type: "put" });
});

app.delete("/", (req, res) => {
    return res.json({ type: "delete" });
});

app.listen(port, () => console.log(`this server listening on ${port}`));
