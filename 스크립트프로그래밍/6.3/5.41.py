#5.41 가장 큰 수의 출현 빈도수

#max함수는 두개의 수를 받아 큰수를 return하는 함수다.
def max(num1, num2) :
    if num1 < num2:
        result = num2
    else:
        result = num1
    return result

def main():
    max1 = 1
    count = 0
    i = 1
    for i in range(1, 100):
        num = eval(input("숫자를 입력하시오(0은 입력 종료) : "))

        #들어온값이 0이면 종료
        if num == 0:
           break

        #max1과 들어온수를 따져서 max1에 다시 넣는다.
        if max(num, max1) > max1:
            max1 = num
            count =0
            
        #가장큰수와 똑같은수가 들어오면 count해준다.
        if num == max1:
            count+=1
    print("가장 큰수는",max1,"입니다.")
    print("가장 큰 수가 나타난 빈도수는",count,"번입니다.")
    
main()
