def isPrime(number):
    divisor = 2
    while divisor <= number / 2:
        if number % divisor == 0:
            # 참이면, number는 소수가 아니다.
            return False 
        divisor += 1
    return True # 소수이다.
