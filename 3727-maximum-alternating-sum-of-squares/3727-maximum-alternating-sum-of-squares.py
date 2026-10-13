class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        ans = 0
        i = 0
        j = len(nums)-1
        for k in range(0, len(nums)):
            nums[k] = nums[k]**2
        nums.sort()
        while(i <= j):
            ans += nums[j]
            j -= 1
            if(i <= j):
                ans -= nums[i]
                i += 1
        return ans