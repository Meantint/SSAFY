const express = require("express");
const multer = require("multer");
const fs = require("fs");
const path = require("path");
const { restart } = require("nodemon");
const AdmZip = require("adm-zip");
const PORT = 8080;

const app = express();

app.set("view engine", "ejs");
app.use(express.urlencoded({ extended: false }));
app.use(express.json());

app.get("/", (req, res) => {
    console.log(__dirname);
    return res.render("index");
});

const upload = multer({
    storage: multer.diskStorage({
        destination: (req, file, done) => {
            done(null, "uploads/");
        },
        filename: (req, file, done) => {
            const ext = path.extname(file.originalname);
            done(null, "test.png");
        },
    }),
    limits: { fileSize: 5 * 1024 * 1024 },
});

app.post("/upload", upload.single("userfile"), (req, res) => {
    console.log(req.file);
});

app.get("/download", async (req, res) => {
    try {
        res.set("Content-Disposition", "attachment; filename=homework.png");
        res.set("Content-Type", "application/octet-stream");

        const file = fs.ReadStream(`${__dirname}/uploads/test.png`);

        return file.pipe(res);
    } catch (err) {
        console.log(err);
    }
});

app.listen(PORT, () => console.log(`server ${PORT}`));
