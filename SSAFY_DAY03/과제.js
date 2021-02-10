let a = document.querySelectorAll('.nav');
let sav_txt = []

for (let i = 0; i < a.length; ++i) {
	console.log(a[i].textContent);
	sav_txt.push(a[i].textContent);
}

console.log(sav_txt);