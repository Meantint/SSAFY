const { nameList } = require("./fileModule");

console.log(nameList);

nameList.then((data) => {
    const nameArr = data.toString().split(",");
    console.log(nameArr);
});
