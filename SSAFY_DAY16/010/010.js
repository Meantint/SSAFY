let str = "AB[100]T[41]ABS[1][5]BTS";

let ans = 0;

for(let i = 0; i < str.length; ++i){
	let low = str.indexOf('[', i);
	if(low === -1){
		break;
	}
	let high = str.indexOf(']', low);
	if(high === -1){
		break;
	}
	
	let res = str.substring(low + 1, high);
	ans += Number(res);

	i = high;
}

console.log(ans);