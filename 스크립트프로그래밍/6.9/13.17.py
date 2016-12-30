#13.17 대용량 데이터 처리하기
import urllib.request

def main():
    #온라인에서 파일을 읽어온다.
    f = urllib.request.urlopen("http://cs.armstrong.edu/liang/data/Salary.txt")
    sumassociate = 0 #
    countassociate=0
    sumassistant = 0
    countassistant = 0
    sumfull = 0
    countfull = 0
    
    #파일이 끝날때까지 반복한다.
    while True:
        txt = f.readline().decode()
        if txt == "":
            break
        #문자열에 assistant이 있을때
        if txt.find('assistant') != -1:
            countassistant+=1
            txt1=txt[txt.find('assistant') + 10:]
            txt2=txt1[:len(txt[txt.find('assistant') + 10:])-2]
            sumassistant = sumassistant + float(txt2)
        #문자열에 associate이 있을때    
        if txt.find('associate') != -1:
            countassociate+=1
            txt1=txt[txt.find('associate') + 10:]
            txt2=txt1[:len(txt[txt.find('associate') + 10:])-2]
            sumassociate = sumassociate + float(txt2) 
        #문자열에 full이 있을때 
        if txt.find('full') != -1:
            countfull+=1
            txt1=txt[txt.find('full') + 5:]
            txt2=txt1[:len(txt[txt.find('full')+5:])-2]
            sumfull = sumfull + float(txt2)
    print("associate의 평균연봉 ",sumassociate/countassociate,"  총연봉은 ",sumassociate)
    print("assistant의 평균연봉은 ",sumassistant/countassistant,"  총연본은 ",sumassistant)
    print("full의 평균연봉은 ",sumfull/countfull," 총연봉은 ",sumfull)
    print("전체직원의 평균연봉은 ",((sumassociate+sumassistant+sumfull)/(countassociate+countassistant+countfull))," 총연봉은 ",(sumassociate+sumassistant+sumfull))
main()
