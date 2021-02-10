let a = "ABCABCMCABCABCMCBBQABC";

let res = 0;
for(let i = 0; i < a.length; ++i){
	let tmp = a.indexOf("ABC", i);
	if(tmp !== -1){
		++res;
		i = tmp;
	}
	else{
		break;
	}
}

console.log(res);