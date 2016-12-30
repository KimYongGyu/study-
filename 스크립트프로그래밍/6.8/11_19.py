#11.19 ( 패턴인식 : 네 개의 연속된 같은 숫자)
#패턴이 4개가 붙어있는지 확인하는 함수 맞으면True 아니면 False반환
def isConseccutiveFour(values):
    for y in range(len(values[0])):
        for x in range(len(values)):
            #열을 넘어가지않게 3을빼서 확인
            if y < len(values[0]) - 3:
                if checkRow(values,x,y):
                    return True
            #행을 넘어가지 않게 3을빼서 확인
            if x < len(values) - 3:
                if checkCol(values,x,y):
                    return True
            #가로세로 크기를 모두 줄여 확인
            if x < len(values) - 3 and y < len(values[0]) - 3:
                if checkAwk1(values,x,y):
                    return True
            #세로크기를 줄이고 왼쪽부터 가로를 줄여확인
            if x < len(values) - 3 and y > 2:
                if checkAwk2(values,x,y):
                    return True
    return False
#가로방향 검사
def checkRow(values,r,c):
    for i in range(1,4):
        if values[r][c+i] == values[r][c]:
            continue
        else:
            return False
    return True

#세로방향 검사
def checkCol(values,r,c):
    for i in range(1,4):
        if values[r+i][c] == values[r][c]:
            continue
        else:
            return False
    return True

#오른쪽 대각선방향 검사
def checkAwk1(values,r,c):
    for i in range(1,4):
        if values[r+i][c+i] == values[r][c]:
            continue
        else:
            return False
    return True

#왼쪽 대각선방향 검사
def checkAwk2(values,r,c):
    for i in range(1,4):
        if values[r+i][c-i] == values[r][c]:
            continue
        else:
            return False
    return True


#2차원 행렬을 만드는 함수
def makeMatrix(rows,cols):
    result = []
    split2 = []
    for i in range(rows):
        print(i+1,"행 숫자",cols,"개 입력 : ",end = "")
        s = input()
        split1 = [eval(x) for x in s.split()]
        for j in split1:
            split2.append(j)
            if len(split2) == cols:
                result.append(split2)
                split2 = []
                break 
    return result

def main():
    rows = eval(input("리스트의 행 개수를 입력 : "))
    cols = eval(input("리스트의 열 개수를 입력 : "))
    matrix = makeMatrix(rows,cols)

    print(isConseccutiveFour(matrix))

main()
