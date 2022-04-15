"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var text = fs.readFileSync(".txt", "utf-8").toString().trim().split("\n");
text.forEach(function (_E) {
    console.log(_E);
});
//# sourceMappingURL=fs_read.js.map