function test() {
    setTimeout(function () {
        console.log("2");
    }, 1000);
}

console.log("1");
// 비동기는 동기 작업이 끝난 후 실행 되기 때문에 setTimeout이 0ms라도 더 늦게(3보다) 실행된다.
console.log(test());
console.log("3");
