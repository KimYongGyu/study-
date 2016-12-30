#11.7 가장 가까운 두 점
import math

points = [[-1, 0, 3], [-1, -1, -1], [4, 1, 1], [2, 0.5, 9], [3.5, 2, -1],
          [3, 1.5, 3], [-1.5, 4, 2], [5.5, 4, -0.5]
#거리구하는 함수
def di(i, j) :
    x1 = points[i][0]
    y1 = points[i][1]
    z1 = points[i][2]
    x2 = points[j][0]
    y2 = points[j][1]
    z2 = points[j][2]
    distance = math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)
    return distance
#각 포인트마다 거리를 반복해서 리스트에 저장
def dist(points) :
    
    dis = []
    for row in range(8) :
        if row == 7 :
            break
        for row1 in range(row, 7) :

            dis.append(di(row, row1+1))

    print(min(dis))
def main() :
    dist(points)
main()
