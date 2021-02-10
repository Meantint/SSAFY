let str = "ABCDEF[1599]AAQ";

let low = str.indexOf('[');
let high = str.indexOf(']');

let res = str.substring(low + 1, high);
let num = Number(res) + 1;

console.log(num);