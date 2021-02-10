let a = "";

for(let i = 0; i < 2; ++i){
	for(let j = 1; j <= 9; ++j){
		a += String(j);
	}
}

let low = 1;
let high = 5;
let result = a.substring(low, high);

console.log(result);