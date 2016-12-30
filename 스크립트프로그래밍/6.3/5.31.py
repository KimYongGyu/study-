# 입력한 년과 월에 맞게 달력을 출력하는 프로그램
year = eval(input("년도를 입력하시오 : "))
day = eval(input("새해 첫 날의 요일을 입력하시오 일(0) 월(1) 화(2) 수(3) 목(4) 금(5) 토(6) : "))
num = 1
month = 1

if day == 0 or day == 1 or day == 2 or day == 3 or day == 4 or day == 5 or  day == 6 :
    while month <= 12:
        sort = day
        print("")
    
        print("\t\t\t", year ,"년 ", month, "월")
        print("-------------------------------------------------------------------")
        print("\t 일\t 월\t 화\t 수\t 목\t 금\t 토")
        while sort > 0:
            # 첫 날을 출력하기 전까지 공백을 출력합니다.
            print("\t", end = format("",">2s"))
            sort = sort - 1
        if month == 2:
            # 2월의 경우 윤년인 경우와 아닌 경우를 나눕니다.
            if ((year % 4 == 0) and (year != 100)) or (year % 400 == 0):
                while num <= 29:
                    print("\t", num, end = format("",">2s"))
                    num += 1
                    if day == 6:
                        # 토요일까지 출력했으면 다음 주로 넘어갑니다.
                        print("")
                        day = 0
                    else:
                        # 토요일이 아닌 다른 요일인 경우 하루씩 증가합니다.
                        day += 1
            else:
                while num <= 28:
                    print("\t", num, end = format("",">2s"))
                    num += 1
                    if day == 6:
                        print("")
                        day = 0
                    else:
                        day += 1
                
# 한 달이 30일인 경우
        elif month == 4 or month == 6 or month == 9 or month == 11:
            while num <= 30:
                print("\t", num, end = format("",">2s"))
                num += 1
                if day == 6:
                    print("")
                    day = 0
                else:
                    day += 1
# 한 달이 31일인 경우
        else:
            while num <= 31:
                print("\t", num, end = format("",">2s"))
                num += 1
                if day == 6:
                    print("")
                    day = 0
                else:
                    day += 1
        month += 1
        num = 1
        print()
else :
    # 새해 첫 날의 요일을 잘못 입력했을 때
    print("날짜를 잘못 입력하였습니다.")
