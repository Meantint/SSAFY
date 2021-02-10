let a = "ABCMINMIN";
let b = "BBQCOCO";
let c = a + b;

let result = [];

for(let i = c.length - 1; i >= 0; i--){
	if(i % 2 === 1){
		continue;
	}
	result.push(c[i]);
}
alert(result);