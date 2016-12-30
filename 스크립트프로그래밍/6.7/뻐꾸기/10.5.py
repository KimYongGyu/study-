#10.5 (고유 숫자 출력하기)

def ifnum(list1):
    i = 0
    list2 = list()
    for i in range(0,10):
        list2.append(list1[i])
        if(list2.count(list1[i]) >= 2):
            list2.remove(list1[i])
    return list2
def printlist(lst):
    for x in lst:
        print(x," ",end='')
def main():#공백으로 10개의 숫자를 입력하세요
    s=input("10개의 숫자를 입력하세요 : ")
    items = s.split()
    list1=[eval(x) for x in items]
    print("중복을 제거한 고유한 숫자 : ",end = '')
    printlist(ifnum(list1))
main()
    
    
