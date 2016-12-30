#8.13 최장접두어

#문자열 s1,s2를 매개변수로 가지는 메소드
#최장 접두어가 무엇인지  확인한다.
def prefix(s1, s2) :
    str1 = len(s1)
    str2 = len(s2)
    count = 0
    #겹치는게 있는지확인한다. 길이만큼
    for i in range (0, str1) :
        if s1[i] == s2[i] :
            count +=1
        #겹치는것이 없으면 그만둔다.
        else :
            break
    return count

def main() :
    s1 = input("문자열을 입력하세요 : ")
    s2 = input("문자열을 입력하세요 : ")
    #겹치는갯수만큼 s1을 출력한다.
    for i in range (0,prefix(s1, s2)):
        print(s1[i], end = '')

main()
