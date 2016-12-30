#5.35 10000미만의 완전수 찾기 프로그램

i = 1

#1부터 10000까지 수를 돌린다.
for i in range(1, 10000) :
    sum = 0
    j = 1
    #돌리는 수를 나눠서 완전수를 찾는다.
    for j in range(1, 9999) :
        if i%j == 0 and i != j :
            sum += j
            j+=1
    if i == sum :
        print(i,end =' ')
    i+=1

