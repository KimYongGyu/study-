#6.45 정다각형 그리기

import turtle

turtle.speed(100)

i=3

#정다각형 그리는 함수
def drawPolygon(x , y , radius, numberOfSides) :
  
        turtle.penup()
        turtle.goto(x,y)
        turtle.pendown()

        turtle.circle(radius, steps = numberOfSides)


def main() :
    drawPolygon(-250, 0, 50, 3)
    drawPolygon(-150, 0, 50, 4)
    drawPolygon(-50, 0, 50, 5)
    drawPolygon(50, 0, 50, 6)
    drawPolygon(150, 0, 50, 7)
    drawPolygon(250, 0, 50, 8)

main()
