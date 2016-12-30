#14.3 각 키워드의 빈도수 세기
import os.path
import sys
def main():
        keywords = ["and","as","assert","break","class",\
                    "continue","def","elif","else","del",\
                    "except","False","finally","for","from",\
                    "global","if","import","in","is","lambda",\
                    "None","nonlocal","not","or","pass","raise",\
                    "return","True","try","while","with","yield"]

        filename = input("파이썬 소스 코드 파일명을 입력하세요. : ").strip()
        #파일이 존재하는지 검사한다.
        if not os.path.isfile(filename):
                print("파일",filename,"이/가 존재하지 않습니다.")
                sys.exit()
        #파일을 오픈한다. 오류를 범하지 않기위해 encoding='utf8'추가
        infile = open(filename,"r", encoding='utf8')
        text = infile.read().split()
        #가각의 키워드의 개수를 저장할 count리스트 생성한다.
        count = [0]*len(keywords)
        for word in text:
                #파일을 공백문자를 기준으로 저장한 리스트 text를 순회.
                if word in keywords:
                        #text의 원소가 keywords에 존재하는 경우에는
                        #그 인덱스의 count값을 1 증가시킨다.
                        i = keywords.index(word)
                        count[i] += 1
        for k in range(len(count)):
                if count[k] > 0:
                        print(keywords[k], " : ", count[k])
main()
        
        
