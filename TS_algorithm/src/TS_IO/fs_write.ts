import fs = require("fs");
import { rawListeners } from "process";
let input = require("fs").readFileSync('TS_IO/.txt').toString().split(' ');
input = ~~input;

let arr : Array<number> = [];

for (let i =0;i < input; i++){
    arr.push(~~(Math.random() * 100));
}

fs.writeFileSync("./randomNumber.txt", arr.toString(), "utf-8");

let inputArray = fs.readFileSync('./randomNumber.txt', "utf-8").toString().trim().split(',');

console.log(inputArray);