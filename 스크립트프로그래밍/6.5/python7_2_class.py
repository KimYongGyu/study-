#7.2(stock 클래스) 회사의 주식을 표현하는 stock이라는 클래스를 설계하시오.

#stock클래스에 생성자 추가.
class stock :
    #stock객체를 생성한다.
    def __init__(self, cid, balance, yearRate) :
        self.cid = cid
        self.balance = balance
        self.yearRate = yearRate
    #stock클래스에 withdraw함수 추가
    def withdraw(self) :
        self.balance -= 2500000
        return self.balance
    #stock클래스에 deposit함수 추가
    def deposit(self) :
        self.balance += 3000000
        return self.balance
        
