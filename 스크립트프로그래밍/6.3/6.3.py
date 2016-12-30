#6.3 (대칭수) 다음 헤더를 갖는 함수를 작성하시오.

def reverse(number) :
    s = str(number)

    #s[::-1] 거꾸로 만들어준다.
    rnumber = s[::-1]
    return rnumber


def isPalindrome(number) :
    if str(number) == reverse(number) :
        return True
    else :
        return False

def main() :
    number = eval(input("정수를 입력하시오:"))
    if isPalindrome(number) == True :
        print("대칭수 입니다.")
    else :
        print("대칭수가 아닙니다.")
main()
