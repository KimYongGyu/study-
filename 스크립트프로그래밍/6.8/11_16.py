#11.16 ( y축 좌표값을 기준으로 점 리스트 정렬하기 )
points = [[4, 34], [1, 7.5], [4, 8.5], [1, -4.5], [1, 4, 5], [4, 6, 6]]
#y 좌표값을 기준으로 정렬된 새로운 점 리스트 반환
def ysort(y) :
    for i in range(len(y)-1) :
        currentMin, currentMinIndex = y[i], i
        for j in range(i+1, len(y)) :
            if currentMin > y[j] :
                currentMin, currentMinIndex = y[j], j
        if currentMinIndex != i:
            y[currentMinIndex], y[i] = y[i], currentMin
    return y

def sort(points) :
    y = []
    a= []
    for row in range(6) :
        y.append(points[row][1])
        ysort(y)
    for i in range(6) :
        for j in range(6) :
            if points[j][1] == y[i] :
                a.append(points[j])
    print(a)

def main() :
    sort(points)
main()
