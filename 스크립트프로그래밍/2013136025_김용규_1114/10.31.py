#10.31 문자열 내 각 숫자의 빈도수
def count(s):
    counts = []
    for i in range(10):
        counts.append(s.count(str(i)))
    for a in range(10):
        if counts[a] > 0 : 
            print(a, " - ", counts[a], "번 나타납니다.")
def main():
    s = input("문자열을 입력하세요 : ")
    count(s)
main()
