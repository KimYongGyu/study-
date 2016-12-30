class Solution:
    def largestNumber(self, num):
        #num의 문자열 형태로 복사
        liststrNum = [str(x) for x in num] 
        pup = []
        strNum = ""
        while len(pup) < len(num):
            maxNum = '0'
            #첫번째문자와 두번째문자의 순서를 바꾸면서
            #가장큰값을 임시 저장소에 저장
            for i in liststrNum:
                str1 = i + maxNum
                str2 = maxNum + i
                if str1 > str2:
                    maxNum = i
            pup.append(maxNum)
            liststrNum.remove(maxNum)
        for i in pup:
            if i == '0' and strNum == '0':
                continue
            else:
                strNum += i
        return strNum
def main():
    n = Solution()
    l = [1,20,23,4,8]
    print("가장 큰수는 ",n.largestNumber(l))
main()
        
