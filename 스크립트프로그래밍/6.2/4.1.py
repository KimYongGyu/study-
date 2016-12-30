#4.1 대수 이차방정식 풀기

import math
a, b, c = eval(input("2차 방정식의 계수(a, b, c)를 입력하시오 : "))

#판별식
D = b * b - 4 * a * c

#루트안에는 양수가 들어가야하기 때문에 경우를 나눳다.
if D >= 0 :
    r1 = (-b + math.sqrt(D)) / (2 * a)
    r2 =  (-b - math.sqrt(D)) / (2 * a)
else :
    r1 = (-b + math.sqrt(-D)) / (2 * a)
    r2 =  (-b - math.sqrt(-D)) / (2 * a)



if D > 0 :
    print("실근은 ", r1, " 이고 ", r2, " 입니다.")
elif D == 0 :
    print("실근은 ", r1, " 입니다.")
else  :
    print("실근은 존재하지 않습니다.")
