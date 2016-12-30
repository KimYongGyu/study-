#4.35 (turtle: 점위치) 점3개를 입력받고 점이 직선의
#     왼쪽 위 오른쪽에 있는지 판단하고 그리는 프로그램

import turtle as a

a1,a2,b1,b2,c1,c2 = eval(input("점 3개의 xy값을 각각 입력하세요 : "))
#펜을든다.
a.penup()
#위치이동
a.goto(a1,a2)
#펜을 내려서 그린다.
a.pendown()
#현위치에 p0를 쓴다.
a.write( "P0")
a.penup()
a.forward(15)
#a1, a2 좌표를 쓴다.
a.write((a1,a2))
a.pendown()
a.goto(b1,b2)
a.write( "P1")
a.penup()
a.forward(15)
a.write( (b1,b2))
a.penup()
a.goto(c1,c2)
a.dot()
a.write( "P2")
a.penup()
a.forward(15)
a.write( (c1,c2))
a.goto(c1,c2-20)

#공식을 사용하여 직선의 어느쪽에있는지 판별한다.
Desk = (b1-a1)*(c2-a2)-(c1-a1)*(b2-a2)
if(Desk >0):
    a.write("직선의 왼쪽에 있다.")
if(Desk==0):
    a.write("직선의  위에 있다.")
if(Desk<0):
    a.write("직선의 오른쪽에 있다.")
