#3.2기하학: 대권거리

import math
#이번에는 math를 import 하여서 삼각함수를 사용했다.
#훨씬 편한것을 느꼇다.

x1, y1 = eval(input("첫 번째 점(위도, 경도)를 입력하세요 : "))
x2, y2 = eval(input("두 번째 점(위도, 경도)를 입력하세요 : "))

d = 6370.01 * math.acos(math.sin(x1 * math.pi/180) * math.sin(x2 * math.pi/180)
                        + math.cos(x1 * math.pi/180)*math.cos(x2 * math.pi/180)
                        * math.cos((y1 - y2) * math.pi/180))

print("두 점 사이의 거리는", d)
