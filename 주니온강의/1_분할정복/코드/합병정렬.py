from re import M

ORDER = True


def Merge(_Start, _Mid, _End, _List):
    Mlist = list()
    i = _Start
    j = _Mid + 1
    while(i <= _Mid and j <= _End):
        if(not((_List[i] >= _List[j]) ^ ORDER)):
            Mlist.append(_List[i])
            i += 1
        else:
            Mlist.append(_List[j])
            j += 1
    if(i <= _Mid):
        Mlist += _List[i: _Mid + 1]
    else:
        Mlist += _List[j: _End + 1]

    for K in range(_Start, _End + 1):
        _List[K] = Mlist[K - _Start]


def Divide(_Start, _End, _List):
    if(_Start < _End):
        mid = (_Start + _End) // 2
        Divide(_Start, mid, _List)
        Divide(mid+1, _End, _List)
        Merge(_Start, mid, _End, _List)


def MergeSort(_List):
    Divide(0, len(_List)-1, _List)


S = [27, 10, 12, 20, 25, 13, 15, 22]
print("Before", S)
MergeSort(S)
print("After", S)
