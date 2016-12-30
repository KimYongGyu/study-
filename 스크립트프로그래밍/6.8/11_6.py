#11.6 대수학: 행렬의 곱
#입력 받은 두 행렬과 곱한 행렬을 출력해주는 함수.
def printlist(matA,matB,matC,row):
    rowA=row
    for i in range(0,rowA):
        l=0
        for j in range(0,rowA*3+3):
            #matA행렬을 출력한다.
            if j <row :
                print(" ",matA[i][l]," ",end='')
                l+=1
                if l == row:
                    l=0
            #행의 수에 따라서 곱셉의 위치를 정해준다.
            if row<j<=row+1:
                if row%2 == 0:
                    if i+1 == row/2:
                        print(" *",end='')
                    else:
                        print("  ",end='')
                
                if row%2 == 1:
                    if i+1 == (row+1)/2:
                        print(" *",end='')
                    else:
                        print("  ",end='')
            #matB행렬을 출력한다.
            if row+1<j<=row*2+1:
                print(" ",matB[i][l]," ",end='')
                l+=1
                if l == row:
                    l=0
            #행의 수에 따라서 는의 위치를 정해준다.
            if row*2+1<j<=row*2+2:
                if row%2 == 0:
                    if i+1 == row/2:
                        print(" =",end='')
                    else:
                        print("  ",end='')   
                if row%2 == 1:
                    if i+1 == (row+1)/2:
                        print(" =",end='')
                    else:
                        print("  ",end='')
            #matC행렬 즉,두행렬을 곱을 출력한다.
            if j>row*2+2:
                print(" ",matC[i][l]," ",end='')
                l+=1
                if l == row:
                    l=0
        print("")
#입력받은 두행렬과 행으로 곱을 만들어주는 함수
def multiplyMatrix(a,b,rowA):
    matC =[]
    for row in range(0,rowA):
        matC.append([])
        for coulum in range(0,rowA):
            matC[row].append([])
    for i in range(0,rowA):
        for j in range(0,rowA):
            matsum =0
            for k in range(0,rowA):
                matsum+=a[i][k]*b[k][j]
            matC[i][j] =matsum
    return matC
#두행렬을 만들어 주는 함수
def matmake(list1):
    i = 1
    while True :
        i2= i*i
        j =len(list1)
        if j == i2 :
            matA = []
            k=0
            for row in range(0,i):
                matA.append([])
                for coulum in range(0,i):
                    matA[row].append(list1[k])
                    k+=1
            break
        i+=1
    return matA , i
#메인 함수
def main():
    s=input("정방행렬1을 띄어쓰기로 입력하세요. : ")
    items = s.split()
    list1=[eval(x) for x in items]
    matA,rowA=matmake(list1)
    s=input("정방행렬2을 띄어쓰기로 입력하세요. : ")
    items = s.split()
    list1=[eval(x) for x in items]
    matB,rowB=matmake(list1)
    if rowA==rowB:
        matC=multiplyMatrix(matA,matB,rowA)
    else:
        print("A의 행 값과 B의 열 값이 일치하지않습니다.")
    printlist(matA,matB,matC,rowA)
main()
