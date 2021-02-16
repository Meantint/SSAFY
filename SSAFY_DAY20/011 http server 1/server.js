const http = require("http");

const server = http.createServer((req, res) => {
    // 응답에 대한 정보를 기록하는 메서드
    res.writeHead(200, "text/html: charset=utf-8");

    // 클라이언트로 보낼 데이터
    res.write("<h1>Hello, world!</h1>");

    // 응답을 종료하는 메서드
    res.end("<p>Hello Server!</p>");
});

server.listen(8500, () => {
    console.log("this server listening on 8500");
});
