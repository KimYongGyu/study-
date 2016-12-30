#11.15 기하학 : 같은직선
import math
#거리를 계산해주는 함수
def get_dis(x1,y1,x2,y2):
    result=math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
    return result
#시티의 위치를 저장하는 함수
def mycityallloc(l,citynum):
    list2=[]
    for j in range(0,citynum*citynum,citynum):
        locsum=0
        for i in range(j,j+citynum):
            locsum+=l[i]
        list2.append(locsum)
    return list2
def main(): 
    citynum=eval(input("도시의 개수를 입력하세요 : "))
    s=input("도시 좌표를 입력하세요 : ")# 엔터가 아니라 스페이스로 나열
    items = s.split()
    locCity=[eval(x) for x in items]
    citynum2=citynum*2
    citylocdis=[]
    for j in range(0,citynum2,2):
        for i in range(0,citynum2,2):
            citylocdis.append(get_dis(locCity[j],locCity[j+1],locCity[i],locCity[i+1]))
    list2 =mycityallloc(citylocdis,citynum)
    for i in range(0,citynum):
        if min(list2) == list2[i]:
            print("중심도시는","(",locCity[2*i],",",locCity[2*i+1],")","에 있습니다.")
main()
