#4.11 월의 일수 계산하기 년과 월을 입력받음

#일수를 알고싶은 년과 월 입력받기
year, month = eval(input("일수를 알고 싶은 년과 월을 입력하시오 : "))

#1,3,5,7,8,10,12월들은 31일로고정
if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12 :
    day = 31
#4,6,9,11월들은 30일로 고정
elif month == 4 or month == 6 or month == 9 or month == 11 :
    day = 30

#2월일 경우 윤년을 따져본다    
elif month == 2 :
    if year % 4 == 0 and year % 100 != 0 or year % 400 ==0 :
        day = 29
    else :
        day = 28
else :
    print("월을 다시 입력하시오 : ")
print(year, "년 ", month, "월은 ", day, "일까지 있습니다.")
