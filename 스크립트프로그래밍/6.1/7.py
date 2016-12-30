investment = eval(input ("투자금을 입력하세요 : "))

interestRate = eval( input( "연이율을 입력하세요 : "))

interestMonth = interestRate /12 / 100

year = eval (input (" 투자 년수를 입력하세요 : " ))

Month = year *12

futureinvestment = investment * pow( ( 1+ interestMonth ) , Month)

print( "누적된 가치는", futureinvestment)
