import fs = require("fs");

let arr = fs.readFileSync("./randomNumber.txt", "utf-8").toString().trim().split(',').map(x => ~~x);

function bubble(_inputData : Array<number>) : Array<number> {
    for (let i = _inputData.length-1; i > 0 ; i--){
        for(let j = 0; j <= i; j++){
            if(_inputData[j] > _inputData[j+1]){
                [_inputData[j], _inputData[j+1]] =  [_inputData[j + 1], _inputData[j]];
            }
        }
    }
    return _inputData;
}

function selection(_inputData : Array<number>) : Array<number>{
    for (let i = 0 ; i < _inputData.length - 1; i++){
        let target = i;
        for(let j = i ; j <= _inputData.length - 1; j++){
            if(_inputData[target] > _inputData[j]){target = j;}
        }
        [_inputData[target], _inputData[i]] = [_inputData[i], _inputData[target]];
    }
    return _inputData;
}

function insertion(_inputData : Array<number>, _order : boolean) : Array<number>{
    //9 8 6 4 3 21 2 5 1 
    //8 9 6 4 3 21 2 5 1 
    //6 8 9 4 3 21 2 5 1 
    //4 6 8 9 3 21 2 5 1 
    //4
    for(let sortedNum = 0; sortedNum < _inputData.length-1; sortedNum++){
        let target = _inputData[sortedNum+1];
        let curIdx = sortedNum;
        while(curIdx >= 0 && !((target < _inputData[curIdx]) !== (_order))){
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
console.log(insertion(arr.slice(), false));//깊은 복사
