#6.16 1년의 총일수 2010년부터 2020년까지 총 일수를 출력하는 테스트 프로그램을작성하세요.

#년도별 일수를 구하는함수
def yearcal(year):
    day=0
    if (year%4==0 and year%100!=0)or year%400==0:
        a=365
    else:
        a=365
    return a

#메인함수
def main():
    allday=0
    for i in range(2010,2021):
        allday+=yearcal(i)
    print("2010년부터 2020년까지 총일수는",allday)

main()
