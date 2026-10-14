class Solution:

    def f(self, nums: list[int], goal: int) -> int:
        if(goal < 0):
            return 0
        count = sum = 0
        n = len(nums)
        r = l = 0
        while(r < n):
            if(nums[r] == 1):
                sum += 1
            while(sum > goal):
                sum -= nums[l]
                l += 1
            count += r-l+1
            r += 1
        return count

    def numSubarraysWithSum(self, nums: list[int], goal: int) -> int:
        return self.f(nums, goal) - self.f(nums, goal-1)