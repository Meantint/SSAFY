// let title = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > a > strong');
// let rate = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong > span');
// let openDate = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > span.txt-info > strong');

// console.log(title.textContent, rate.textContent, openDate.textContent);

// let title2 = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > a > strong');
// let rate2 = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > div > strong > span');
// let openDate2 = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > span.txt-info > strong');

// title2.textContent = "삼겹살과 그대라면";
// rate2.textContent = "5%";
// openDate2.textContent = "1985.07.07";

// const onePoster = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a');
// const threePoster = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a');

// const oneContent = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents');
// const threeContent = document.querySelector('#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents');

// let temp;
// temp = threePoster.innerHTML;
// threePoster.innerHTML = onePoster.innerHTML;
// onePoster.innerHTML = temp;

// temp = threeContent.innerHTML;
// threeContent.innerHTML = oneContent.innerHTML;
// oneContent.innerHTML = temp;

/* 위에꺼가 문제 */

let a = document.querySelectorAll('.thumb-image');

console.log(a);

for (let i = 0; i < a.length; ++i) {
	console.log(a[i]);
}
