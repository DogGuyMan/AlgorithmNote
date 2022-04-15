import fs = require("fs");

let data = fs.readFileSync("./src/1_sort/randomNumber.txt").toString().trim().split(',').map(x => ~~x);

console.log(data);

function Partition(_S: number, _E: number, _inputData: Array < number > ): number {
    let Pivot = _inputData[_S];
    let LOW = _S + 1,
        P_HIGH = _E;
    
    while (LOW <= P_HIGH) {
        while (_inputData[LOW] < Pivot){LOW++;}
        while (_inputData[P_HIGH] > Pivot){P_HIGH--;}
        if (LOW <= P_HIGH){
            [_inputData[LOW], _inputData[P_HIGH]] = [_inputData[P_HIGH], _inputData[LOW]];
            LOW++; P_HIGH--;
        }
    }

    let Pidx = P_HIGH;
    [ _inputData[_S] , _inputData[Pidx] ] = [ _inputData[Pidx], _inputData[_S] ];
    return Pidx;
}

function QuickSort(_S: number, _E: number, _inputData: Array < number > ) {
    if (_S < _E) {
        let P = Partition(_S, _E, _inputData);
        QuickSort(_S, P - 1, _inputData);
        QuickSort(P + 1, _E, _inputData);
    }
}
QuickSort(0, data.length - 1, data)
console.log(data);