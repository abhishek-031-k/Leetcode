class Solution:

    def f(self, nums: list[int], k: int)-> int:
        l = r = count = 0
        n = len(nums)
        while(r < n):
            if(nums[r] % 2 != 0):
                k -= 1
            while(k < 0):
                if(nums[l] % 2 != 0):
                    k += 1
                l += 1
            if(k >= 0):
                count += r-l+1
            r += 1
        return count


    def numberOfSubarrays(self, nums: list[int], k: int) -> int:
        return self.f(nums, k) - self.f(nums, k-1)