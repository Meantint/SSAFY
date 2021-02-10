let a = prompt("새 문자열 입력");

let b = a.split(" ");

let result = [];
for(let i = 0; i < b.length; i++){
	result.push(b[i]);
}

alert(result);