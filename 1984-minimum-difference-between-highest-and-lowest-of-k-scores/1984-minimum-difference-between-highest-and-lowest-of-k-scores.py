class Solution:
    def minimumDifference(self, nums: list[int], k: int) -> int:
        if(k == 1):
            return 0
        nums.sort()
        ans = 1e9
        for i in range(0, len(nums)-k+1):
             ans = min(ans, nums[k+i-1] - nums[i])
        return ans