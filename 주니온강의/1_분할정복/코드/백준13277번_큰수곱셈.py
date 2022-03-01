from unittest import result


def ladd(_u, _v):
    n = len(_u) if (len(_u) > len(_v)) else len(_v)
    result = []
    carry = 0
    for k in range(n):
        i = _u[k] if k < len(_u) else 0
        j = _v[k] if k < len(_v) else 0
        value = i + j + carry
        carry = value // 10
        result.append(value % 10)
    if (carry > 0):
        result.append(carry)
    return result


def fillZero(_u, _num):
    for k in range(_num):
        _u.append(0)
    return _u


def lmul(_u, _v):
    n = len(_u) if (len(_u) > len(_v)) else len(_v)
    result = []
    if(len(_u) == 1 and len(_v) == 1):
        mul = _u[0] * _v[0]
        result.append(mul//10)
        result.append(mul % 10)
        return result
    m = n//2
    x = _u[0:m-1]
    y = _u[m:]
    z = _v[0:m-1]
    w = _v[m:]
    A = fillZero(lmul(x, z), m*2)
    B = fillZero(lmul(y, z), m)
    C = fillZero(lmul(x, w), m)
    D = lmul(y, w)
    result = ladd(ladd(A[::-1], B[::-1]), ladd(C[::-1], D[::-1]))
    return result


u = [5, 6, 7, 8, 9, 0]
v = [9, 8, 7, 6, 5, 4, 3, 2, 1]
print(567890 * 987654321)

print(lmul(u[::-1], v[::-1])[::-1])
