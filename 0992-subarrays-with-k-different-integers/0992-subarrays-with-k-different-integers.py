class Solution:

    def f(slef, nums: list[int], k: int) -> int:
        l = r = count = 0
        n = len(nums)
        mpp = {}
        while(r < n):
            mpp[nums[r]] = mpp.get(nums[r], 0) + 1
            while(len(mpp) > k):
                mpp[nums[l]] -= 1
                if(mpp[nums[l]] == 0):
                    del mpp[nums[l]]
                l += 1
            if(len(mpp) <= k):
                count += r-l+1
            r += 1
        return count


    def subarraysWithKDistinct(self, nums: list[int], k: int) -> int:
        return self.f(nums, k) - self.f(nums, k-1)