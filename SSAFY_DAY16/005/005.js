let a = "KFCOCOBBQMINMINC";

let res = [];

for(let i = 0; i < a.length; i++){
	let tmp = a.indexOf('C', i);
	if(tmp !== -1){
		res.push(tmp);
		i = tmp;
	}
	else{
		break;
	}
}

console.log(res);
console.log(...res);