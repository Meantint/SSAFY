const kfc = {
    plate: ["BTS", "OK", "HAHAHA", "TT"],

    run() {
        const result = this.plate.map((e) => e.length);
        console.log(result);
    },
};

kfc.run();

const bts = [
    { num: 1, weight: 50, name: "bts" },
    { num: 2, weight: 40, name: "kfc" },
    { num: 3, weight: 60, name: "mc" },
];

let result = bts.filter((e) => e.name.indexOf("bts") === -1);
for (let mem of result) {
    console.log(mem);
}
