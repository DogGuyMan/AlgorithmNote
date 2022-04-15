"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var data = fs.readFileSync("./src/1_sort/randomNumber.txt", "utf-8").toString().trim().split(",").map(function (x) { return ~~x; });
//function MergeSort(_inputData : Array<number>) : Array<number>{}
function Merge(_S, _M, _E, _inputData) {
    var MData = [];
    var i = _S, j = _M + 1;
    while (i <= _M && j <= _E) {
        if (_inputData[i] < _inputData[j]) {
            MData.push(_inputData[i++]);
        }
        else {
            MData.push(_inputData[j++]);
        }
    }
    if (i <= _M) {
        while (i <= _M) {
            MData.push(_inputData[i++]);
        }
    }
    else {
        while (j <= _E) {
            MData.push(_inputData[j++]);
        }
    }
    MData.forEach(function (_E) { _inputData[_S++] = _E; });
}
function Divide(_S, _E, _inputData) {
    if (_S < _E) {
        var M = ~~(((_S + _E) / 2));
        Divide(_S, M, _inputData);
        Divide(M + 1, _E, _inputData);
        Merge(_S, M, _E, _inputData);
    }
}
function MergeSort(_inputData) {
    Divide(0, _inputData.length - 1, _inputData);
    return _inputData;
}
console.log(data);
console.log(MergeSort(data.slice()));
//# sourceMappingURL=mergeSort.js.map