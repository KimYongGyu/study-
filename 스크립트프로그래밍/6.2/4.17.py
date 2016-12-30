#4.17 (게임 : 가위,바위,보)

import random

a= eval(input("가위(0) 바위(1) 보(2) : "))

#random.randrange(a,b)는 a부터b까지 무작위수를 나오게한다.
b= random.randrange(0,2)

if b==0 and a==0:
    print("컴퓨터는 가위입니다. 당신은 가위입니다. 비겼습니다.")
if b==0 and a==1:
    print("컴퓨터는 가위입니다. 당신은 바위입니다. 이겼습니다.")
if b==0 and a==2:
    print("컴퓨터는 가위입니다. 당신은 보입니다. 졋습니다.")

if b==1 and a==0:
    print("컴퓨터는 바위입니다. 당신은 가위입니다. 졋습니다.")
if b==1 and a==1:
    print("컴퓨터는 바위입니다. 당신은 바위입니다. 비겼습니다.")
if b==1 and a==2:
    print("컴퓨터는 바위입니다. 당신은 보입니다. 이겼습니다.")

if b==2 and a==0:
    print("컴퓨터는 보입니다. 당신은 가위입니다. 이겼습니다.")
if b==2 and a==1:
    print("컴퓨터는 보입니다. 당신은 바위입니다. 졋습니다.")
if b==2 and a==2:
    print("컴퓨터는 보입니다. 당신은 보입니다. 비겻습니다.")
    



    
