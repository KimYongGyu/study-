#소계와 팁비율을 입력받는다.
total,tip = eval( input(" 소계와 팁비율을 입력하세요. : "))

#팁과 총액을 출력한다.
print( "팁은", total*tip*1.0/100 )
print("총액은 ", total+total*tip*1.0/100, "입니다. ")
