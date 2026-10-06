class Solution:
    def canJump(self, nums: list[int]) -> bool:
        maxi = 0
        for i in range (0, len(nums)):
            if(maxi < i):
                return False
            maxi = max(maxi, i + nums[i])
        return True