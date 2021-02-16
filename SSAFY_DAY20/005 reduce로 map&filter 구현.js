const arr = [1, 2, 3, 4, 5, 6, 7];

let arrMap = arr.reduce((acc, cur) => {
    acc.push(cur * 10);

    return acc;
}, []);

let arrFilter = arr.reduce((acc, cur) => {
    if (cur % 2 == 0) {
        acc.push(cur);
    }
    return acc;
}, []);

console.log(arrMap);
console.log(arrFilter);
