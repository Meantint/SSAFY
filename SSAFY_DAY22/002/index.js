const express = require("express");
const app = express();
const { pool } = require("./mysql");
const PORT = 8080;

app.set("view engine", "ejs");
app.use(express.urlencoded({ extended: false }));
app.use(express.json());

app.get("/", async (req, res) => {
    const data = await pool.query("select * from todo");
    try {
        res.render("index", { data: data[0] });
    } catch (err) {
        res.render("error 404");
    }
});

app.post("/add", async (req, res) => {
    const todo = req.body.todo;
    console.log(todo);
    try {
        const data = await pool.query("insert into todo SET ?", [
            { todo, checked: false },
        ]);
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});

app.get("/update/check/:id", async (req, res) => {
    const { id } = req.params;
    const { checked } = req.query;
    console.log(id, checked);

    try {
        const data = await pool.query(
            "update todo set checked = ? where id = ?",
            [checked, id]
        );
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});

app.get("/update/todo/:id", async (req, res) => {
    const { id } = req.params;
    const { todo } = req.query;
    console.log(id, todo);

    try {
        const data = await pool.query(
            "update todo set checked = ? where id = ?",
            [todo, id]
        );
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});

app.get("/delete/todo/:id/", async (req, res) => {
    const { id } = req.params;

    try {
        const data = await pool.query("delete from todo where ?", [{ id }]);
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});

app.listen(PORT, () => console.log(`server ${PORT}`));
