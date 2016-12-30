#11.15 ( 기하학 : 같은 직선)
#같은 직선에 있는지 확인하여 True와 False를 반환
def sameLine(p) :
    count=0
    for i in range(4,9,2):
        if (p[2]-p[0])*(p[i+1]-p[1])-(p[i]-p[0])*(p[3]-p[1]) == 0:
            count+=1
    if count == 3:
        return True
    else:
        return False
def main() :
    coordi=input("다섯 개의 점을 입력하세요:  ")# 엔터가 아니라 스페이스로 나열
    items = coordi.split()
    points=[eval(x) for x in items]
    if sameLine(points) :
        print("다섯 개의 점은 같은 직선 위에 있습니다.")
    else :
         print("다섯 개의 점은 같은 직선 위에 있지 않습니다.")

main()
