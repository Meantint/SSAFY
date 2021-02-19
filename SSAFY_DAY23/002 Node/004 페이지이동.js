const puppeteer = require("puppeteer");
const fs = require("fs");

const main = async () => {
    // Browser 생성한다.
    // Headless -> Default true  -->  false 바꾸면 브라우저가 실행된다.
    const browser = await puppeteer.launch({ Headless: false });

    const [page, page2, page3] = await Promise.all([
        browser.newPage(),
        browser.newPage(),
        browser.newPage(),
    ]);

    await Promise.all([
        page.goto("https://www.naver.com"),
        page2.goto("https://www.google.com"),
        page3.goto("https://www.daum.net"),
    ]);

    console.log("작업중...");

    page3.waitForTimeout(10000);

    await page.close();
    await page2.close();
    await page3.close();

    // '그' 브라우저를 종료한다. puppeteer 종료한다.
    await browser.close();
};

main();
