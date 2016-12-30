def gcd(number) :
    for i in range(1, number[0]+1):
        if number[0] % i == 0 and number[1] % i == 0  and number[2] % i == 0 and number[3] % i == 0  and number[4] % i == 0 :
            listgcd = i
    return listgcd

def main() :
    number = []
    for i in  range(5):
        number.append(eval(input()))

    print(gcd(number))
main()
