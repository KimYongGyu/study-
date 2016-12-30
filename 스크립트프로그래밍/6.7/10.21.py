#10.21

def main():
    x= False
    list1 =[]
    list2 = []
    i=0
    for i in range(0,100):
        list1.append(x)
    #첫번째 학생
    for i in range(0,100):
        list1.pop(i)
        list1.insert(i,True)
    
    #두번째부터 백번째 학생
    for j in range(1,100):
        list2 = [] +stu(list1,j)
        print(list2)
        print("")
       # printlist(list2)
        
    #열려있는 사물함
    for k in range(0,100):
        if list2[k] ==True :
            print(k+1,end='')
            print("번째 사물함은 열려있습니다.")

def printlist(lst):
    for x in lst:
        print(x)
        
def stu(list1,stunum):
    list2 =[] + list1
    i =0
    stunum +=1
    for i in range(stunum,100,stunum):
        if list2.pop(i) == True :
            list2.insert(i,False)
        elif list2.pop(i) == False :
            list2.insert(i,True)
    return list2

main()
    
    
