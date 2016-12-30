#6.26메르센 소수 찾기

#받은 소수를 메르센 소수로 바꿔준다.
def mer(num):
    mernum = 2**num-1
    return mernum

#메인함수에서는 소수를 찾는다.
def main():
    global i
    global j
    j=2
    i=2
    a=0
    print(" p  2^p - 1")
    for i in range(2 , 32):
         for j in range(2,i):
             if i%j==0:
                 break
             j+=1
         if i==j:
            print(format(i,"2.0f"),end="")
            print(" ",mer(i))
         i+=1            
         
       
main()
