#6.23 밀리초를 시,분,초로 변환하기

import math

def converMillis(millis):
    totalsec=millis/1000
    minu = 0
    sec = 0
    hour =0
    
    minu = totalsec /60
    sec = totalsec%60

    hour = minu/60
    minu = minu%60

    hour = math.floor(hour)
    minu = math.floor(minu)
    sec = math.floor(sec)

    print(hour,":",minu,":",sec)

def main():
    millis=eval(input("밀리초를 입력하세요"))
    converMillis(millis)

main()
