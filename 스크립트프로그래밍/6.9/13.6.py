# 13.6 단어 개수 세기
import urllib.request
#인터넷파일을 읽는다.
infile = urllib.request.urlopen("http://www.handotrading.com/sub_kor/index.php.txt")
s = infile.read().decode()
#문자열과 리스트 생성
string = ""
wordList = []
count = []
for i in s :
    #특수문자가있을경우를 세준다.
    if i in "~`!@#$%^&*()_+={}[];:',\n<|.\>/?-\"" :
        continue
    else :
        string += i

lowerS = string.lower()
split = lowerS.split()

for i in split : 
    
    if i not in wordList :
        count.append(i)
    wordList.append(i)
#단어와 단어의갯수출력
for i in count :
    print(i, "", wordList.count(i))
