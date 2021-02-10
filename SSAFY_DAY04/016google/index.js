const toggleButton = document.querySelector('.toggle-button');
const bodyBackground = document.querySelector('#body-background');
const headerNav = document.querySelector('.header-nav-list-wrapper');
const imgIconWrappers = document.querySelectorAll('.img-icon-wrapper');
const bookmarkText = document.querySelectorAll('.bookmark-text');

const searchInput = document.querySelector('#search-input');
const bookmarkWrapper = document.querySelector('.bookmark-wrapper');

toggleButton.addEventListener('click', function(){
	// console.log('hello');
	toggleButton.innerHTML = "다크 모드";
	toggleButton.classList.toggle('toggle-button-darkmode');
	headerNav.classList.toggle('text-darkmode');
	bodyBackground.classList.toggle('body-background-darkmode');

	for(let i = 0; i < imgIconWrappers.length; ++i){
		imgIconWrappers[i].classList.toggle('img-icon-wrapper-darkmode');
	}

	for(let i = 0; i < bookmarkText.length; ++i){
		bookmarkText[i].classList.toggle('img-icon-wrapper-darkmode');
	}

	if(toggleButton.classList.contains('toggle-button-darkmode')){
		toggleButton.innerHTML = '일반 모드';
	}
})

searchInput.addEventListener('keyup', function(e){
	if(e.code === 'Enter'){
		if(e.target.value === ''){
			alert("검색어를 입력하지 않으셨습니다.");
			return;
		}
		alert(e.target.value + "를 검색하셨습니다.");

		window.open("https://www.google.com/search?q=" + e.target.value, '_blank');
	}
})

const bookmarkPlus = document.querySelector('#bookmark-plus');

bookmarkPlus.addEventListener('click', function(e){
	const bookmarkItem = document.querySelectorAll('.bookmark-item');

	const item = bookmarkItem[bookmarkItem.length - 1];
	const clone = item.cloneNode(true);
	item.after(clone);
})