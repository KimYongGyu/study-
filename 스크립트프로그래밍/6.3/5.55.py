#5.55 체스판을 그리는 프로그램을 작성하시오.

import turtle
import math

fill = 0
row = 1

turtle.speed(10)
turtle.right(45)
#y를 -200부터 50단위로 175+1만큼돌린다.
for y in range (-200, 175 + 1, 50):
    #x를 -200 부터 50단위로 175+1 만큼 돌린다.
    for x in range (-200 , 175 + 1, 50):
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()

        #홀수번째 줄을 출력
        if row % 2 != 0:
            if fill == 0:
                turtle.begin_fill()
                turtle.color("black")
                turtle.circle(25 * math.sqrt(2), steps = 4)
                turtle.end_fill()
                fill = 1
            else:
                turtle.circle(25 * math.sqrt(2), steps = 4)
                fill = 0

        #짝수번째 줄을 출력
        else:
            if fill == 1:
                turtle.begin_fill()
                turtle.color("black")
                turtle.circle(25 * math.sqrt(2), steps = 4)
                turtle.end_fill()
                fill = 0
                
            else:
                turtle.circle(25 * math.sqrt(2), steps = 4)
                fill = 1
    #줄이 한칸씩 올라갈때마다 row를 올려준다.
    row = row + 1
    
turtle.penup()
turtle.goto(-200, -200)
turtle.pendown()
turtle.color("grey")
turtle.pensize(3)
turtle.circle(200 * math.sqrt(2), steps = 4)
