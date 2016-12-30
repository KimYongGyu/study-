#7.7(대수학 :2x2연립방정식) 연립방정식에 대한  LinearEquation 클래스를 설계하시오

class LinearEquation :

    def __init__(self,a,b,c,d,e,f) :
        self.__a =a
        self.__b =b
        self.__c =c
        self.__d =d
        self.__e =e
        self.__f =f

    def getA(self):
        return self__a
    
    def getB(self):
        return self__b
    
    def getC(self):
        return self__c
    
    def getD(self):
        return self__d
    
    def getE(self):
        return self__e
    
    def getF(self):
        return self__f

    def isSolvable(self) :
        if (self.__a * self.__d) - (self.__b * self.__c) != 0 :
            return True

    def getX(self) :
        if LinearEquation.isSolvable(self) :
            x = ((self.__e * self.__d) - (self.__b * self.__f)) / ((self.__a * self.__d) - (self.__b * self.__c))
            return print("x는 ",x)
        else :
            return print("ad-bc가 0입니다.")
    
    def getY(self) :
        if LinearEquation.isSolvable(self) :
            y = ((self.__a * self.__f) - (self.__e * self.__c)) / ((self.__a * self.__d) - (self.__b * self.__c))
            return print("y는 ",y)
        else :
            return print("ad-bc가 0입니다.")
