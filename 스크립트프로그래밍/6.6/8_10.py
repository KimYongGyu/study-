#8.10 10진수를 2진수로 변환하기

#10진수를 2진수로 변환하는 함수
def decimalToBinary(a) :
    s=''
    #몫이 0보다 크면 계속 반복
    while a>0 :
        #나머지와 몫을 나누어 만들어준다.
        a, r = divmod(a,2)
        #나머지가 9보다 크면 아스키코드값으로 십의자리수를 빼고 가지고있는다.
        if(r>9):
            r=chr(ord('a')+r-10)
        s= str(r)+s
    return s


def main():
    number = eval(input("10진수를 입력하세요 : "))
    print(decimalToBinary(number))


main()
    
