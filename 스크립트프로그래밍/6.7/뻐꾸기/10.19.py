import random

def ballgame(number, slot) :
    allball = []
    for row in range(0,number):
        allball.append([])
        for coulum in range(0,slot-1):
            allball[row].append(random.randrange(1,3))
        
    for i in range(0,len(allball)):
        print("")
        for j in range(0,len(allball[i])):
            if(allball[i][j] ==1):
                print('L',end='')
            else:
                print('R',end='')

    
    slotloc= []
    for row1 in range(0,number):
        slotloc.append([])
        for cou1 in range(0,slot):
            slotloc[row1].append(1)
    print("")
         
    for a in range(0,number):
        loc =allball[a].count(2) - 1
        n1 = number-1
        if slotloc[n1][loc] == 0:
            for c in range(0,number):
                if slotloc[n1-c][loc] == 1:
                    slotloc[n1-c][loc] = 0
                    break
        elif slotloc[n1][loc] == 1:
            slotloc[n1][loc]=0    
            
    for i in range(0,len(slotloc)):
        for j in range(0,len(slotloc[i])):
            if slotloc[i][j] == 1:
                print(' ',end='')
            if slotloc[i][j] == 0 :
                print(0,end='')
        print("")
# 1: L 2:R
def main() :
    number = eval(input("떨어뜨릴 공의 개수를 입력하세요 : "))
    slot = eval(input("콩 기계의 슬롯 개수를 입력하세요 : "))
    ballgame(number, slot)
main()
