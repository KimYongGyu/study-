class Solution:
    def compareStrings(self, A, B):
        #비교할 문자열이 0이면 무조건 포함되어있다
        if len(B) ==0 :
            return True
        #비교할문자열이 0이 아니지만 비교당할 문자열이 0이면
        #무조건 포함되어있지않다.
        if len(A) == 0 and len(B)!=0:
            return False
        
        for i in range(0,len(B)) :
            if A.find(B[i]) != -1 : 
                if A.count(B[i]) < B.count(B[i]):
                    return False
        return True
def main():
    n = Solution()
    s1 = "12312345cG"
    s2 = "123"
    print(s1)
    print(s2)
    print(n.compareStrings(s1,s2))


main()
