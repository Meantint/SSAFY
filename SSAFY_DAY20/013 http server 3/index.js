const http = require("http");
const fs = require("fs").promises;

const server = http.createServer(async (req, res) => {
    console.log(req.method);
    console.log(req.url);
    try {
        if (req.method === "GET") {
            if (req.url === "/") {
                res.writeHead(200, {
                    "Content-Type": "text/html; charset=utf-8",
                });
                const data = await fs.readFile("index.html");
                return res.end(data);
            } else if (req.url === "/a") {
                res.writeHead(200, {
                    "Content-Type": "text/html; charset=utf-8",
                });
                const data = await fs.readFile("a.html");
                return res.end(data);
            } else if (req.url === "/b") {
                res.writeHead(200, {
                    "Content-Type": "text/html; charset=utf-8",
                });
                const data = await fs.readFile("b.html");
                return res.end(data);
            }
        }
    } catch (err) {
        console.log(err);
    }
});

server.listen(8902, () => {
    console.log("this server listening on 8902");
});
