def count(s):
    counts = []
    for i in range(10):
        counts.append(s.count(str(i)))
    
    for i in range(10):
        if counts[i] > 0 : 
            print(i, " - ", counts[i], "번 나타납니다.")

def main():
    s = input("문자열을 입력하세요 : ")
    count(s)
main()
