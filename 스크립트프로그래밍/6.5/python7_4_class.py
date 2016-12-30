#7.4(Fan 클래스) 팬을 표현하는 Fan 클래스를 설계하시오.

class fan :
    #fan 객체를 생성한다.

    CONST_SLOW = 1
    CONST_MEDIUM = 2
    CONST_FAST = 3

    a=0
    #클래스 생성자
    def __init__(self,speed = CONST_SLOW , on =False,radius = 5,color = 'blue'):
        
        self.__speed = speed
        self.__on = on
        self.__radius = radius
        self.__color = color
    #출력함수
    def printfan(self):
        print("속도  ",self.__speed)
        print("전원  ",self.__on)
        print("크기  ",self.__radius)
        print("색상  ",self.__color)
        
    
            
