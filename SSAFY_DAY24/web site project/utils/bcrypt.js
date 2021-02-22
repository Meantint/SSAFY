const bcrypt = require("bcrypt");

// 암호화 하는데 필요한 값
const saltRounds = 10;

const hashPassword = async (password) => {
    try {
        const salt = await bcrypt.genSalt(saltRounds);
        // console.log(salt)
        const hashedPassword = await bcrypt.hash(password, salt);
        // console.log(hashedPassword)
        return hashedPassword;
    } catch (err) {
        return new Error(err);
    }
};
// 비교 로직
const comparePassword = async (password, hashedPassword) => {
    try {
        return await bcrypt.compare(password, hashedPassword);
    } catch (err) {
        return new Error(err);
    }
};
module.exports = { hashPassword, comparePassword };
