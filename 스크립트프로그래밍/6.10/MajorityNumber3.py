class Solution:
    def majorityNumber(self, nums, k):
        # write your code here
        for i in range(0,len(nums)):
            if nums.count(nums[i])>(len(nums)/k) :
                return nums[i]

def main():
    s = Solution()
    print("Majority Number : ",s.majorityNumber([3,1,2,3,2,3,3,4,4,4], 3))

main()
    
