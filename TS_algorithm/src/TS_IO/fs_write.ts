import fs = require("fs");
import { rawListeners } from "process";
let input = require("fs").readFileSync('./src/TS_IO/.txt').toString().split(' ');
input = ~~input;

let arr : Array<number> = [];

for (let i =0;i < input; i++){
    arr.push(~~(Math.random() * 400));
}

fs.writeFileSync("./src/1_sort/randomNumber.txt", arr.toString(), "utf-8");

let inputArray = fs.readFileSync('./src/1_sort/randomNumber.txt', "utf-8").toString().trim().split(',');

console.log(inputArray);