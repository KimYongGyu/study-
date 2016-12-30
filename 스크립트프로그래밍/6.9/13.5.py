#13.5 (문자열 대체하기)
def main():
    fName = input("파일명을 입력하세요 : ")
    srcStr = input("교체될 이전 문자열을 입력하세요 : ")
    desStr = input("이전 문자열을 대체할 새로운 문자열을 입력하세요 :")

    #fName이라는 이름을 가진 파일을 읽기형식으로읽어 txt로 받아온다.
    f =open(fName,'r')
    txt = f.read()
    f.close()
    #txt 문자열을 바꾸고싶은문자2개를 바꾼다.
    txt = txt.replace(srcStr,desStr)
    #fName이라는 이름을 가진 파일을 쓰기형식으로 읽어 txt를 저장한다.
    ref = open(fName,'w')
    ref.write(txt)
    ref.close()
    f.close()
main() #main함수를 호출한다.
