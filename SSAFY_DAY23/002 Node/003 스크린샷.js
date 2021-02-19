const puppeteer = require("puppeteer");

const main = async () => {
    // Browser 생성한다.
    // Headless -> Default true  -->  false 바꾸면 브라우저가 실행된다.
    const browser = await puppeteer.launch();

    // 생성된 Browser로 페이지를 생성한다.
    const page = await browser.newPage();

    // 생성된 페이지로 goto 메서드를 사용해 이동할 수 있다 (목적지 필요)
    // 크로마움을 실행하고 새페이지를 만들어서 구글로 이동한다.
    await page.goto("https://www.google.com");
    await page.screenshot({ path: "screenshot.png" });

    // '그' 브라우저를 종료한다. puppeteer 종료한다.
    await browser.close();
};

main();
