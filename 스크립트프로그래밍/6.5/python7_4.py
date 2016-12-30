#7.4(Fan 클래스) 팬을 표현하는 Fan 클래스를 설계하시오.

from python7_4_class import fan

def main():

    #각 팬들을 초기화시킨후 출력하는 메인이다.
    fan1 = fan(fan.CONST_FAST,True,10,'yellow')
    print("fan1")
    fan1.printfan()
    print("\n")
    fan2 = fan(fan.CONST_MEDIUM, False, 5 , 'blue')
    print("fan2")
    fan2.printfan()

main()
