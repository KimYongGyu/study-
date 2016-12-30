#5.46 통계 : 평균과 표준편차 계산하기

import math

num = 0
nSum = 0
nSumSquare = 0

#10개의 숫자를 입력받기 위해 반복문 사용
for i in range (1,11):
    num = eval(input("10개의 숫자를 입력하시오:"))
    nSum += num
    nSumSquare += num ** 2

#입력 받은 값들을 공식으로 값을 계산
m = nSum / 10
s = math.sqrt((nSumSquare - m * nSum) / 9)

print("평균은", m, "입니다.")
print("편차는", s, "입니다.")
