#8.8 2진수를 10진수로 변환

#2진수를 10진수로 변환하는 함수
def binaryToDecimal(binaryString) :
    size = len(binaryString)
    dec =0
    num = eval(binaryString)
    #0부터 길이까지 반복
    for i in range(0, size) :
        #2진수일경우 0아니면 1이기때문에 0인경우는 생략
        if eval(binaryString[i]) == 1 :
            #자릿수만큼 2의 승을 곱해줌
            a = 2**(size -i-1)
            #십진수는 만든 a에서 각자리수만큼 0or1만큼 곱해준다. 그것을 계속합산
            dec += (a * eval(binaryString[i]))
    return dec
                    
def main() :
    binaryString = input("이진수를 입력하세요 : ")
    print("십진수는 ", end = '')
    print(binaryToDecimal(binaryString))
main()
