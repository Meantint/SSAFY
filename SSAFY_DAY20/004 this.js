// 변수
const brand = "ADIDAS";

// 객체
const nike = {
    brand: "NIKE",
    size: 38,
    series: ["에어포스", "조던", "에어맥스"],

    run() {
        console.log(brand); // ADIDAS
        console.log(this.brand); // NIKE
        console.log(this.series.forEach((e) => e === "에어포스")); // forEach의 결과 값은 항상 undefined이다.
    },
};

nike.run();
