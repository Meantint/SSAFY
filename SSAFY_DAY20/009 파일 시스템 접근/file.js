const fs = require("fs");

fs.readFile("./context.txt", (err, data) => {
    if (err) {
        throw err;
    }
    console.log(data);
    console.log(data.toString());
});

const fs1 = require("fs").promises;

fs1.readFile("./context.txt")
    .then((data) => {
        console.log(data);
        console.log(data.toString());
    })
    .catch((err) => {
        console.log(err);
    });
