#7.2(stock 클래스) 회사의 주식을 표현하는 stock이라는 클래스를 설계하시오.

from python7_2_class import stock
#stock클래스를 임포트한다.

def main() :
    #stock클래스의 Account이름의 객체생성
    Account = stock(1122, 20000000, 4.5)

    Account.withdraw()
    print("출금한 후 잔액 : ", Account.balance)
    
    Account.deposit()
    print("입금한 후 잔액 : ", Account.balance)
    
    mRate = Account.yearRate / 12
    mInterest = mRate * Account.balance / 100

    print("ID :", Account.cid, "잔액 : ", Account.balance, " 월이율 : ", mRate, " 월이자 : ", mInterest)
main()
    
