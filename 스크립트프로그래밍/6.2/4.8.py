#4.8(3개의 정수정렬하기)

a,b,c= eval(input("정수 세개를  입력하세요  : "))

#a가 b보다 크거나 같을때
if a>=b :
    if b>= c:
        print("오름차순 정렬",c,b,a)
    if b<c :
        if a>=c:
            print("오름차순 정렬",b,c,a)
        if a<c:
            print("오름차순 정렬",b,a,c)
            
#a가 b보다 작을때
if a<b:
    if a>c:
        print("오름차순 정렬",c,a,b)
    if a<c:
        if b>=c:
            print("오름차순 정렬",a,c,b)
        if b<c:
            print("오름차순 정렬",a,b,c)
