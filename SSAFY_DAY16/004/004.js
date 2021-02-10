// indexOf("문자열", 시작할 index)
// 대소문자 구분 필요
// 처음으로 나오는 인덱스 출력
// 못 찾는 경우 -1 return

let a = 'HELLOWORLDHELLO';

let g1 = a.indexOf('HELLO');
let g2 = a.indexOf('HELLO', 6);

console.log("g1 = " + g1 + ", " + "g2 = " + g2);
console.log(`g1 = ${g1}            g2 = ${g2}`);