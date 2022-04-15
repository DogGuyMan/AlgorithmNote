"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var input = require("fs").readFileSync('TS_IO/.txt').toString().split(' ');
input = ~~input;
var arr = [];
for (var i = 0; i < input; i++) {
    arr.push(~~(Math.random() * 100));
}
fs.writeFileSync("./randomNumber.txt", arr.toString(), "utf-8");
var inputArray = fs.readFileSync('./randomNumber.txt', "utf-8").toString().trim().split(',');
console.log(inputArray);
//# sourceMappingURL=fs_write.js.map