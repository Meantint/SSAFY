const KFC = () => {
    console.log("KFC");
};
const MC = () => {
    console.log("MC");
};
const BK = () => {
    console.log("BK");
};

arr = [KFC, MC, MC, BK, BK, KFC];

arr.forEach((e) => {
    e();
});
