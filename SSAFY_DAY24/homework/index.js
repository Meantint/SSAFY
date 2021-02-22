const express = require("express");
const app = express();
const PORT = 8080;
const multer = require("multer");
const cookieParser = require("cookie-parser");
const path = require("path");
const db = require("./models");
const { hashPassword, comparePassword } = require("./utils/bcrypt");

app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.set("view engine", "ejs");

const upload = multer({
    storage: multer.diskStorage({
        destination: (req, res, done) => {
            done(null, "uploads/");
        },
        filename: (req, file, done) => {
            const ext = path.extname(file.originalname);
            done(
                null,
                path.basename(file.originalname, ext) + Date.now() + ext
            );
        },
    }),
});

const authentication = async (req, res, next) => {
    // console.log(req.cookies["loginId"])

    if (req.cookies["loginId"]) {
        try {
            const userInformation = await db["user"].findOne({
                where: {
                    id: req.cookies["loginId"],
                },
            });
            res.locals.user = userInformation.dataValues;
        } catch (err) {
            res.locals.user = null;
        }
    }
    next();
};
app.use(authentication);

//메인 페이지
app.get("/", (req, res) => {
    return res.render("index");
});

// 로그인 페이지
app.get("/login", (req, res) => {
    return res.render("login");
});

// 회원가입 페이지
app.get("/signup", (req, res) => {
    return res.render("signup");
});

// 게시판 페이지
app.get("/board", async (req, res) => {
    try {
        const data = await db["board"].findAll({
            include: [
                { model: db["user"], attributes: ["id", "name"] },
                { model: db["file"] },
            ],
        });
        const result = data.map((el) => el.get({ plain: true }));
        return res.render("board", { boards: result });
    } catch (err) {
        res.render("board");
    }
});

// 게시글 작성페이지
app.get("/create", (req, res) => {
    return res.render("create");
});

app.post("/register", async (req, res) => {
    try {
        const { name, hobby, age, email, password } = req.body;
        const hashedPassword = await hashPassword(password);
        const data = await db["user"].create({
            name: name,
            hobby: hobby,
            age: age,
            email: email,
            password: hashedPassword,
        });
        return res.render("logic", { type: "register", result: true });
    } catch (err) {
        console.log(err);
        return res.render("logic", { type: "register", result: false });
    }
});

app.post("/login", async (req, res) => {
    try {
        const { email, password } = req.body;
        // 1차 DB 검색
        const data = await db["user"].findOne({
            where: {
                email: email,
            },
        });
        // console.log(data);

        // 암호화된 비밀번호와 DB에 있는 암호화된 비밀번호를 비교한다.
        const hashedPassword = data.dataValues.password;
        const result = await comparePassword(password, hashedPassword);
        // true인 경우 로그인 성공
        if (result === true) {
            res.cookie("loginId", data.dataValues.id, {
                // 쿠키 도난 방지
                expires: new Date(Date.now() + 1000 * 60 * 60 * 24 * 7),
                // 웹서버에서만 쿠키 접근할 수 있게 default는 false
                httpOnly: true,
            });
            return res.render("logic", { type: "login", result: true });
        }
    } catch (err) {
        console.log(err);
        return res.render("logic", { type: "login", result: false });
    }
});

app.get("/logout", (req, res) => {
    res.clearCookie("loginId");
    res.locals.user = null;
    return res.redirect("/");
});

app.post("/post", upload.single("file"), async (req, res) => {
    const { title, content } = req.body;
    try {
        const post = await db["board"].create({
            title: title,
            content: content,
            user_id: res.locals.user.id,
        });
        const boardId = post.dataValues.id;

        // 존재한다면
        if (req.file) {
            await db["file"].create({
                filename: req.file.filename,
                originalname: req.file.originalname,
                board_id: boardId,
            });
        }

        return res.render("logic", { type: "post", result: true });
    } catch (err) {
        return res.render("logic", { type: "post", result: true });
    }
});

app.get("/download/:id", async (req, res) => {
    const fileData = await db["file"].findOne({
        where: {
            id: req.params.id,
        },
    });
    const { filename, originalname } = fileData.dataValues;
    return res.download(`./uploads/${filename}`, originalname);
});

app.use(express.static("./static"));
app.listen(PORT, () => console.log(`this server listening on ${PORT}`));
