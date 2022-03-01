def Partition(_Start, _End, _List):
    PivotVal = _List[_Start]
    Low = _Start + 1
    High_P = _End
    while(Low <= High_P):
        while(_List[Low] < PivotVal):
            Low += 1
        while(_List[High_P] > PivotVal):
            High_P -= 1
        if(Low <= High_P):  # 일단 통일성을 주려고 <= 했는데 같은인덱스를 굳이 바꿀 필요 있을까?
            _List[Low], _List[High_P] = _List[High_P], _List[Low]
    PivotIdx = High_P
    _List[_Start], _List[PivotIdx] = _List[PivotIdx], _List[_Start]
    return PivotIdx


def QuickSort(_Start, _End, _List):
    if(_Start < _End):
        P = Partition(_Start, _End, _List)
        QuickSort(_Start, P-1, _List)
        QuickSort(P + 1, _End, _List)


def Start_QSort(_List):
    QuickSort(0, len(_List)-1, _List)


S = [26, 5, 37, 1, 61, 11, 59, 15, 48, 19]

print(S)
Start_QSort(S)
print(S)
