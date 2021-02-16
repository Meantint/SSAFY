const fs = require("fs").promises;

const nameList = fs.readFile("./nameList.txt");

module.exports = { nameList };
