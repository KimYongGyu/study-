#10.12 최대공약수 계산하기
def gcd(number) :
    list1 = []
    for i in  range(5):
        list1.append(eval(input()))
    for i in range(1, list1[0]+1):
        if list1[0] % i == 0 and list1[1] % i == 0  and list1[2] % i == 0 and list1[3] % i == 0  and list1[4] % i == 0 :
            listgcd = i
    return listgcd
def main() :
    print(gcd(1))
main()
