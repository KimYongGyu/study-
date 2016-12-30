#5.21 (피라미드 패턴으로 숫자 출력하기) 다음의 결과값을 출력하는 중첩 for 루프를 작성하시오

import math
i = 1
a = 2
blank =7
b=1
p=7
o=1
z=0
zz=0
xx=1
u=0
for i in range(1,8):
    #앞쪽에 띄어쓰기를 위해 빈칸을 만드는 반복문
    for blank in range(1,p):
        print("   ",end =' ')
        blank+=1
        #숫자를 하나씩 써주는 반복문
    for b in range(0,o):
        # 줄바꿈을 하지않기위해 end =' '을 사용함
        print(format(a**z,"3d"),end =' ')
        
        z+=1
        b+=1
    o+=1
    z=0
    #줄어드는 숫자를 위해서 새로운 반복문 사용
    for xx in range(0,u):
        
        print(format(a**zz,"3d"),end =' ')
       
        zz-=1
        xx+=1
    u+=1
    zz=i-1
      #한줄이 입력되면 줄 바꿈
    print("\n")
    p-=1
    i+=1
    
