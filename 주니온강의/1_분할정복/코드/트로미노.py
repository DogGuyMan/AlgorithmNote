import random as rand


def Tromino(_board, _startRow, _startCol, _size, _xrow, _xcol):
    if(_size == 1):
        return
    else:
        # 반띵된 라인
        # 나누기 2한다는것은 비트연산을 옆으로 옮긴다라고 생각할 수 있다.
        midRow = _startRow + (_size // 2)
        midCol = _startCol + (_size // 2)
        # 굳이 X가 아니더라도 이미 칠한부분은 X처럼 생각하겠다.
        # 어차피 X든 이미 칠해진곳이든 다시 칠할수 없다는점에서말이다
        xPart1row, xPart1col = midRow-1, midCol - 1  # 1사분면
        xPart2row, xPart2col = midRow-1, midCol  # 2사분면
        xPart3row, xPart3col = midRow, midCol - 1  # 3사분면
        xPart4row, xPart4col = midRow, midCol  # 4사분면

        if(_xrow < midRow and _xcol < midCol):
            FillCenterExcept(_board, midRow, midCol, 1)
            xPart1row, xPart1col = _xrow, _xcol
        elif(_xrow < midRow and _xcol >= midCol):
            FillCenterExcept(_board, midRow, midCol, 2)
            xPart2row, xPart2col = _xrow, _xcol
        elif(_xrow >= midRow and _xcol < midCol):
            FillCenterExcept(_board, midRow, midCol, 3)
            xPart3row, xPart3col = _xrow, _xcol
        elif(_xrow >= midRow and _xcol >= midCol):
            FillCenterExcept(_board, midRow, midCol, 4)
            xPart4row, xPart4col = _xrow, _xcol

        Tromino(_board, _startRow, _startCol, _size // 2, xPart1row, xPart1col)
        Tromino(_board, _startRow, midCol, _size // 2, xPart2row, xPart2col)
        Tromino(_board, midRow, _startCol, _size // 2, xPart3row, xPart3col)
        Tromino(_board, midRow, midCol, _size // 2, xPart4row, xPart4col)
        # board에 ㄴ ㄱ 나무토막 채워넣는작업임
        # 2*2 에 특정 part(사분면) 딸랑 하나만 제외하곤 나머지 2*2를 채우겠다는 의미


def FillCenterExcept(_board, mrow, mcol, part):
    global tromino_count
    tromino_count += 1
    if(part != 1):
        _board[mrow-1][mcol-1] = tromino_count
    if(part != 2):
        _board[mrow-1][mcol] = tromino_count
    if(part != 3):
        _board[mrow][mcol-1] = tromino_count
    if(part != 4):
        _board[mrow][mcol] = tromino_count


def PrintBoard(_board):
    rowLen = len(_board)
    colLen = len(_board[0])
    if(rowLen == colLen):
        for i in range(rowLen):
            for j in range(colLen):
                if(_board[i][j] < 0):
                    # %는 뭐지? end는 뭐지?
                    print("%3s" % "X", end="")
                else:
                    print("%3s" % _board[i][j], end="")
            # print()하면 그냥 \n한건가보다..
            print()


# 보드 사이즈
m = 4
# 보드에 x(-1) 표시할 좌표
xrow = rand.randint(0, m-1)
xcol = rand.randint(0, m-1)

# 트로미노 카운트? -> +1하면서 진행하므로 0으로 저장
# 트로미노 ㄴ ㄱ 나무토막 몇개 썼는지 카운트
tromino_count = 0

# 보드 만들기 ???
# 000...000을 range(m)만큼 넣어준다는뜻인듯?
# 2차원 배열 들어가는것은 트로미노 카운트이다.
board = [[0] * m for _ in range(m)]

# -1로 초기화
board[xrow][xcol] = -1

Tromino(board, 0, 0, m, xrow, xcol)
PrintBoard(board)
