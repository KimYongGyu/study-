#7.6(대수학 : 2차 방정식) 2차 방정식 QuadraticEquation 클래스를 설계하시오. 
from python7_6_class import QuadraticEquation

def main():
    a,b,c = eval(input("a,b,c 값을 입력하세요."))

    userQuadraticEquation = QuadraticEquation(a,b,c)
    userQuadraticEquation.solve()

main()
