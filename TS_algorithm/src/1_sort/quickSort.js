"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var data = fs.readFileSync("./src/1_sort/randomNumber.txt").toString().trim().split(',').map(function (x) { return ~~x; });
console.log(data);
function Partition(_S, _E, _inputData) {
    var _a, _b;
    var LOW = _S + 1, P_HIGH = _E;
    var Pivot = _inputData[_S];
    console.log("".concat(Pivot, " ").concat(LOW, " ").concat(P_HIGH));
    while (LOW <= P_HIGH) {
        while (_inputData[LOW] < Pivot) {
            LOW++;
        }
        while (_inputData[P_HIGH] > Pivot) {
            P_HIGH--;
        }
        if (LOW <= P_HIGH) {
            _a = [_inputData[P_HIGH], _inputData[LOW]], _inputData[LOW] = _a[0], _inputData[P_HIGH] = _a[1];
        }
    }
    var Pidx = P_HIGH;
    _b = [_inputData[Pidx], _inputData[_S]], _inputData[_S] = _b[0], _inputData[Pidx] = _b[1];
    return Pidx;
}
function QuickSort(_S, _E, _inputData) {
    if (_S < _E) {
        var P = Partition(_S, _E, _inputData);
        QuickSort(_S, P - 1, _inputData);
        QuickSort(P + 1, _E, _inputData);
    }
}
QuickSort(0, data.length - 1, data);
console.log(data);
//# sourceMappingURL=quickSort.js.map