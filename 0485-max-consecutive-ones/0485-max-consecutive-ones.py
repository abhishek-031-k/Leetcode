class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        maxi = 0
        count = 0
        for i in range(0, len(nums)):
            if(nums[i] == 1):
                count += 1
                maxi = max(maxi, count)
            else:
                count = 0    
        return maxi        