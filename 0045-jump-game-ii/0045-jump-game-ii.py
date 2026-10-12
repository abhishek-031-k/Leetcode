class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        l = r = jumps = 0
        while(r < n-1):
            far = 0
            for ind in range(l, r+1):
                far = max(far, ind + nums[ind])
            l = r + 1
            r = far
            jumps += 1
        return jumps