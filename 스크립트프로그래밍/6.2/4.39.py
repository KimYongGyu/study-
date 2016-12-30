#4.39 turtle 2개의 원 두원에 대한 중점좌표 반지름을 입력받고
#                    원의 내부에있는지 판별하고 그리는 프로그램

import turtle as t
import math

#좌표와 반지름 입력받는다.
centerX1, centerY1, radius1 = eval(input("중점좌표와 반지름을 입력하시오 : "))
centerX2, centerY2, radius2 = eval(input("중점좌표와 반지름을 입력하시오 : "))

t.penup()
t.goto(centerX1, centerY1 - radius1)
t.pendown()
t.circle(radius1)
t.penup()


t.goto(centerX2, centerY2 - radius2)
t.pendown()
t.circle(radius2)

#중점사이 거리를 구한다.
distance = math.sqrt((centerX1 - centerX2) * (centerX1 - centerX2) + (centerY1 - centerY2) * (centerY1 - centerY2))

#어떤원이 더작은지 판별하고 반지름차를 구한다.
if radius1 >= radius2 :
    rDistance = radius1 - radius2
    bigRadius = radius1
    smallRadius = radius2
else :
    rDistance = radius2 - radius1
    bigRadius = radius2
    smallRadius = radius1

#구했던 정보를 사용하여 판별한다.
if  distance > rDistance and distance < radius1 + radius2 :
    t.write("두원이 겹칩니다.")

elif distance + smallRadius < bigRadius :
    t.write("한 원이 다른 원 안에 있습니다.")
    
elif distance > (radius1 + radius2) :
    t.write("겹치지 않습니다.")
