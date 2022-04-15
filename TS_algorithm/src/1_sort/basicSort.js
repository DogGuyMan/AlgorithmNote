"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var arr = fs.readFileSync("randomNumber.txt", "utf-8").toString().trim().split(',').map(function (x) { return ~~x; });
function bubble(_inputData) {
    var _a;
    for (var i = _inputData.length - 1; i > 0; i--) {
        for (var j = 0; j <= i; j++) {
            if (_inputData[j] > _inputData[j + 1]) {
                _a = [_inputData[j + 1], _inputData[j]], _inputData[j] = _a[0], _inputData[j + 1] = _a[1];
            }
        }
    }
    return _inputData;
}
function selection(_inputData) {
    var _a;
    for (var i = 0; i < _inputData.length - 1; i++) {
        var target = i;
        for (var j = i; j <= _inputData.length - 1; j++) {
            if (_inputData[target] > _inputData[j]) {
                target = j;
            }
        }
        _a = [_inputData[i], _inputData[target]], _inputData[target] = _a[0], _inputData[i] = _a[1];
    }
    return _inputData;
}
function insertion(_inputData, _order) {
    //9 8 6 4 3 21 2 5 1 
    //8 9 6 4 3 21 2 5 1 
    //6 8 9 4 3 21 2 5 1 
    //4 6 8 9 3 21 2 5 1 
    //4
    for (var sortedNum = 0; sortedNum < _inputData.length - 1; sortedNum++) {
        var target = _inputData[sortedNum + 1];
        var curIdx = sortedNum;
        while (curIdx >= 0 && !((target < _inputData[curIdx]) !== (_order))) {
            _inputData[curIdx + 1] = _inputData[curIdx--];
        }
        _inputData[curIdx + 1] = target;
    }
    return _inputData;
}
//console.log(arr);
//console.log(bubble(arr.slice()));//깊은 복사
////bubble(arr) 참조 : 얕은 복사 
//console.log(arr);
//console.log(selection(arr.slice()));//깊은 복사
console.log(arr);
console.log(insertion(arr.slice(), false)); //깊은 복사
//# sourceMappingURL=basicSort.js.map