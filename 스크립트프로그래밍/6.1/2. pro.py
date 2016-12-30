print("0~1000사이의 정수를 입력하세요 : ")
inta = eval( input ())

a = inta //100
e = inta %100
b = e//10
c = e%10
d= a+b+c

print("각 자리수의 합은",d)
