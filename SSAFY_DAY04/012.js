const id = document.querySelector('.id');
const password = document.querySelector('.password');
const passwordCheck = document.querySelector('.password-check');
const signup = document.querySelector('.signup');
const passwordStatus = document.querySelector('.password-status');
const checkInput = document.querySelector('.check-input');

signup.addEventListener('click', function(e){
	if(id.value && password.value && passwordCheck.value && checkInput.value){
		if(password.value === passwordCheck.value){
			alert("회원가입이 완료되었습니다");
		}else{
			alert("비밀번호가 서로 일치하지 않습니다");
		}
	}else{
		if(!id.value){
			alert("id를 입력해주세요");
		}
		else if(!password.value || !passwordCheck.value){
			alert("password를 입력해주세요");
		}
		else if(!checkInput.checked){
			alert("개인 정보 이용 동의를 체크해주셔야 합니다");
		}
	}
})

passwordStatus.addEventListener('keyup', function(e){
	if(e.target.value === passwordCheck.value){
		passwordStatus.textContent = '비밀번호가 일치합니다';
	}
	else{
		passwordStatus.textContent = '비밀번호가 일치하지 않습니다';
	}
})