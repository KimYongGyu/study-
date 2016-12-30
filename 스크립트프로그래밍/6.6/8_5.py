#8.3 지정된 문자열의 빈도수
#빈도수 확인 함수
def count(s1, s2) :
    return s1.count(s2)
def main() :
    s1 = input("문자열을 입력하세요 : ")
    s2 = input("몇번 나왔는지 알고싶은 단어를 입력하세요 : ")
    print(count(s1, s2))
main()
