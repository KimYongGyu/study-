#6.17My Triangle 모듈 삼각형의 세변의 값을읽고 삼각형의 넓이를 계산하는 프로그램
import math

#입력한 세변을 삼각형이 맞는지 확인하는 함수
def Valid(side1, side2, side3) :
    s1 = 0
    s2 = 0
    nmax = 0
    if side1 > side2 :
        if side1 > side3 :
            nmax = side1
            s1 = side2
            s2 = side3
        else :
            nmax = side3
            s1 = side1
            s2 = side2
    else :
        if side2 > side3 :
            nmax = side2
            s1 = side1
            s2 = side3
        else :
            nmax = side3
            s1 = side1
            s2 = side2
    if nmax < s1 + s2 :
        return True
    else :
        return False

#세변의 길이를 이용해 넓이를 구하는 함수
def area(side1, side2, side3) :
    if Valid(side1, side2, side3) == True :
        s = (side1 + side2 + side3) /2
        #삼각형의 넓이 공식사용
        tArea = math.sqrt(s*(s-side1)*(s-side2)*(s-side3))
        print("삼각형의 넓이 : ", tArea)
    else :
        print("세 변을 잘못 입력했습니다.")
        
def main() :
    side1 = eval(input("한 변의 길이를 입력하시오 : "))
    side2 = eval(input("한 변의 길이를 입력하시오 : "))
    side3 = eval(input("한 변의 길이를 입력하시오 : "))

    area(side1, side2, side3)
main()
