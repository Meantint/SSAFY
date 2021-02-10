const searchInput = document.querySelector('#search-input');
searchInput.addEventListener('keyup', function(e){
	if(e.code === 'Enter'){
		if(e.target.value === ''){
			alert("검색어를 입력하지 않으셨습니다.");
			return;
		}
		alert(e.target.value + "를 검색하셨습니다.");

		window.open("https://m.search.naver.com/search.naver?sm=mtp_hty.top&where=m&query=" + e.target.value, '_blank');
	}
})