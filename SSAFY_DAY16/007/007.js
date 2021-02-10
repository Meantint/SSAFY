let a = "BTSMINBTSMINBTSKKOPSM";

let str_list = ["SM", "MIN", "OP", "VO", "TSM"];

let answer = 0;
let answer_name = "";

for(let i = 0; i < str_list.length; ++i){
	let cnt = 0;
	for(let j = 0; j < a.length; ++j){
		let tmp = a.indexOf(str_list[i], j);
		if(tmp !== -1){
			++cnt;
			j = tmp;
		}
		else{
			break;
		}
	}
	if(answer < cnt){
		answer = cnt;
		answer_name = str_list[i];
	}
}

alert(answer_name);