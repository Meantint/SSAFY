const express = require("express");
const { pool } = require("./mysql");
const PORT = 8080;

const app = express();
app.use(express.urlencoded({ extended: false }));

app.get("/", async (req, res) => {
    return res.json({ data: "Hello World" }); // 서버에서 프론트로 보내는 것
});

app.get("/:id", async (req, res) => {
    const data = await pool.query("select * from user");
    console.log(req.params);
    return res.json({ data: data });
});

app.listen(PORT, () => console.log(`server ${PORT}`));
