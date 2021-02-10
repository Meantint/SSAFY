let a = prompt("세 문자열 입력")

let b = a.split(" ");
let cnt = 0;
if(b[0] == b[1]){
	if(b[0] === b[2]){
		alert("Very Good!");
	}
	else{
		alert("Two");
	}
}
else{
	if(b[0] === b[2]){
		alert("Two");
	}
	else if(b[1] === b[2]){
		alert("Two");
	}
	else{
		alert("Only One");
	}
}