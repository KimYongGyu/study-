class Solution:
    def singleNumber3(self, A):
        #nums set를 생성한다.
        nums = set()
        #A를 계속 순회해서 따져본다.
        for i in A :
            if i not in nums:
                #세트에없으면 추가
                nums.add(i)
                #있는 것이라면 삭제
            else :
                nums.remove(i)
        return nums
def main():
    n = Solution()
    l = [1,2,3,3,2,4,1,5]
    print(n.singleNumber3(l))

main()
