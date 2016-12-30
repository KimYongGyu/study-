#8.3(패스워드 검사하기)

def ifpass(s): #패스워드가 올바른지 확인하는 메소드
    a= True
    b= True
    c= True
    if len(s)<8 : #길이가 8개이하면 false로 반환
        a = False
    if s.isdigit() == True and s.isalnum() == False: #숫자나 문자관리
        b = False
    check=0
    check_b =0
    check_c =0
    for i in range(0,len(s)) :
        if ord(s[i]) >=41 and ord(s[i])<= 90: #숫자나 문자관리
            if ord(s[i]) >=97 and ord(s[i])<= 122:
                check_b+=1
        if ord(s[i]) >=48 and ord(s[i])<= 57: #숫자나 문자관리
            check_c+=1
        if ord(s[i]) >=49 and ord(s[i])<= 57 : #최소 2개이상숫자관리
            check+=1
    if check_b == len(s) :
        b =False
    if check_c == len(s) :
        b =False
    if check < 2 :
        c = False
    else :
        c = True
    #모든조건에 충족되면 올바른 패스워드로 출력 아닐경우는 else로들어간다
    if a == True and b == True  and c == True  :
        print("올바른 패스 워드 입니다.")
    else :
        print("올바르지 않은 패스워드 입니다.")
def main():
    s = input("패스워드를 입력하세요 : (8개이상, 문자숫자혼합, 최소2개숫자)")
    ifpass(s)
main()



