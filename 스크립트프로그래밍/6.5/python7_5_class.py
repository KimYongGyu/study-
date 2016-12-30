#7.5(기하학 : 정다각형) RegularPolygon이라는 클래스를 설계하시오.

import math

class RegularPolygon :
    def __init__(self, n=3, side=1 , x=0, y=0) :
        self.__n = n
        self.__side = side
        self.__x = x
        self.__y = y

    def setN(self,n) :
        self.__n = n
    def getN(self) :
        return self.__n
    def setSide(self,side) :
        self.__side = side
    def getSide(self) :
        return self.__side
    def setX(self,x) :
        self.__x = x
    def getX(self) :
        return self.__x
    def setY(self,y) :
        self.__y = y
    def getY(self) :
        return self.__y
    #둘레를 구하는 함수.
    def getPerimeter(self) :
        per = self.__side * self.__n
        return per
    #넓이를 구하는 함수.
    def getArea(self) :
        Area = (self.__n * self.__side * self.__side) / (4 * math.tan(math.pi / self.__n))
        return Area
