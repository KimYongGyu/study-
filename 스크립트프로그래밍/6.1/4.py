number = eval(input("정수를 입력하시오."))
number1 = number // 1000
number1Total = number % 1000
number2 = number1Total // 100
number2Total = number1Total % 100
number3 = number2Total // 10
number4 = number2Total % 10

print(number1)
print(number2)
print(number3)
print(number4)

