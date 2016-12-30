import random
board = [
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.'],
        ['.','.','.','.','.','.','.','.']]
result = []
a = []
def testPos(row,col):
    for (i,j) in result:
        if len(result) != 0:
            if row == i:
                return False
            if col == j:
                return False
            if abs(row - i) == abs(col - j):
                return False
    return True
c = True
def place(row):
    a=[]
    b=[]
    global c

    
    if(row > 7):
        for i in range(8):
            a = [i for i in result]

    else:
         for col in range (8):
             if testPos(row,col):
                result.append((row,col))
                place(row + 1)
                a.append((row, col))
                result.remove((row,col))
    if len(a) > 7 and c == True:
        for (i, j) in result :
            for x in range(8) :
                for y in range(8) :
                    if x==i and y==j:
                        board[x][y] = 'Q'
        for x in range(8) :
            for y in range(8) :
                print(board[x][y], end = '')
            print()
        c = False
    



result.append((0, random.randint(0,8)))
place(1)




