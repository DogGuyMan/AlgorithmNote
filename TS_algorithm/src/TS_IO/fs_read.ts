import fs = require("fs");

let text : Array<string> = fs.readFileSync(".txt", "utf-8").toString().trim().split("\n");

text.forEach(_E => {
    console.log(_E);
})