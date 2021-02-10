function erase(str, index, cnt){
	let a = str.substring(0, index);
	let b = str.substring(index + cnt, str.length);

	return a + b;
}

function insert(str, index, target){
	let a = str.substring(0, index);
	let b = str.substring(index, str.length);

	return a + target + b;
}