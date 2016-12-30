#7.6(대수학 : 2차 방정식) 2차 방정식 QuadraticEquation 클래스를 설계하시오. 
import math

class QuadraticEquation:
    #QuadraticEquation객체를 생성한다.

    def __init__(self,a,b,c):
        self.__a =a
        self.__b =b
        self.__c =c

    def getA(self):
        return self.__a

    def getB(self):
        return self.__b

    def getC(self):
        return self.__c
    #판별식을 따져주는 함수
    def getDiscriminant(self):
        if (self.__b*self.__b) - (4*self.__a*self.__c) <0:
            return 0
        elif (self.__b*self.__b) - (4*self.__a*self.__c) ==0:
            return 1
        elif (self.__b*self.__b) - (4*self.__a*self.__c) >0:
            return 2

    def getRoot1(self):
        return (-self.__b + math.sqrt((self.__b*self.__b) - (4*self.__a*self.__c)))/2*self.__a

    def getRoot2(self):
        return (-self.__b - math.sqrt((self.__b*self.__b) - (4*self.__a*self.__c)))/2*self.__a

    def solve(self) :
        if QuadraticEquation.getDiscriminant(self)==0 :
            print("이 방정식은 해가 없습니다.")
            
        if QuadraticEquation.getDiscriminant(self) ==1 :
            print(QuadraticEquation.getRoot1(self))
            
        if QuadraticEquation.getDiscriminant(self) ==2 :
            print(QuadraticEquation.getRoot1(self), ",",QuadraticEquation.getRoot2(self))

        
