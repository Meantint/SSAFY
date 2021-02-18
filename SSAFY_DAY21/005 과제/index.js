const express = require("express");
const axios = require("axios");
const app = express();
const PORT = 8080;

app.set("view engine", "ejs");
app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.get("/", async (req, res) => {
    try {
        // ejs에 전달 해줘야 하는 값들 : 글의 갯수, page
        const allAlbums = await axios.get(
            "https://jsonplaceholder.typicode.com/albums/"
        );
        // 앨범 개수
        const count = allAlbums.data.length;
        const page = req.query.page;

        const response = await axios.get(
            "https://jsonplaceholder.typicode.com/albums/",
            {
                params: {
                    _start: page && page > 0 ? 6 * (page - 1) : 0,
                    _limit: 6,
                },
            }
        );

        res.render("index", {
            data: response.data,
            count: count,
            page: page ? page : 1,
        });
    } catch (error) {
        res.render("error");
    }
});

app.get("/:id", async (req, res) => {
    try {
        // ejs에 전달 해줘야 하는 값들 : 글의 갯수, page
        const allPhotos = await axios.get(
            `https://jsonplaceholder.typicode.com/photos/?albumId=${req.params.id}`
        );
        // 앨범 개수
        const count = allPhotos.data.length;
        const page = req.query.page;

        const response = await axios.get(
            `https://jsonplaceholder.typicode.com/photos/?albumId=${req.params.id}`,
            {
                params: {
                    _start: page && page > 0 ? 6 * (page - 1) : 0,
                    _limit: 6,
                },
            }
        );

        res.render("photo", {
            data: response.data,
            cur_id: req.params.id,
            count: count,
            page: page ? page : 1,
        });
    } catch (error) {
        res.render("error");
    }
});

app.listen(PORT, () => console.log(`this server listening on ${PORT}`));
