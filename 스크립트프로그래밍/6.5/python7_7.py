#7.7(대수학 :2x2연립방정식) 연립방정식에 대한  LinearEquation 클래스를 설계하시오

from python7_7_class import LinearEquation

def main():
    
    a,b,c,d,e,f=eval(input("ax+by=e , cx+by=f 에서 a,b,c,d,e,f 를 입력하세요"))
    userLinearEquation = LinearEquation(a,b,c,d,e,f)
    userLinearEquation.getX()
    userLinearEquation.getY()
    
main()
