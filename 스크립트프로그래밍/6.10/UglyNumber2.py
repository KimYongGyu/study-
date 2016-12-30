#Ugly Number
class Solution:
    def nthUglyNumber(self,n):
        #1 부터시작
        result = [1] 
        while True:
            nthUgly = result[-1]
            #리스트의 길이가 n이 될 때까지 반복
            if len(result) == n: 
                return nthUgly
            tmp = []
            for i in result:
                #UglyNumber에 2,3,5를 각각 곱한 값도 UglyNumber이다.
                for j in i*2, i*3, i*5:
                    #그 중 현재 UglyNumber보다 큰 값을 임시 리스트에 저장.
                    if j > nthUgly: 
                        tmp.append(j)
            #임시 리스트에서 가장 작은 값을 결과 리스트에 더한다.
            result.append(min(tmp)) 
        
def main() :
    n = Solution()
    num = eval(input("n을 입력하세요. : "))
    print(n.nthUglyNumber(num))
    
main()
