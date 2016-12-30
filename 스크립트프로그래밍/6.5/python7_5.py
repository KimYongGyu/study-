#7.5(기하학 : 정다각형) RegularPolygon이라는 클래스를 설계하시오.

from python7_5_class import RegularPolygon
#python7_5_class 파일에서 RegularPolygon 클래스를 임포트한다.

def main() :

    #클래스의 객체생성및 초기화 디폴트 매개변수 사용.
    p0 = RegularPolygon()
    p1 = RegularPolygon(6, 4)
    p2 = RegularPolygon(10, 4, 5.6, 7.8)

    print("둘레는 : ", p0.getPerimeter(), ", 넓이는 : ", p0.getArea())
    print("\n")
    print("둘레는 : ", p1.getPerimeter(), ", 넓이는 : ", p2.getArea())
    print("\n")
    print("둘레는 : ", p2.getPerimeter(), ", 넓이는 : ", p2.getArea())

    
main()
