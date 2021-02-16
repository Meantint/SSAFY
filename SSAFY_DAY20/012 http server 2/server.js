const http = require("http");
const fs = require("fs").promises;

const server = http.createServer(async (req, res) => {
    try {
        const data = await fs.readFile("./index.html");
        res.writeHead(200, "text/html: charset=utf-8");
        res.end(data);
    } catch (err) {
        console.log(err);
        res.writeHead(200, "text/html: charset=utf-8");
        res.end(err.message);
    }
});

server.listen(8800, (req, res) => {
    console.log("this server listening on 8800");
});
