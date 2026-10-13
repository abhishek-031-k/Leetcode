class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        maxi = l = r = zero = 0
        n = len(nums)
        while(r < n):
            if(nums[r] == 0):
               k -= 1
            if(k < 0):
                if(nums[l] == 0):
                    k += 1
                l += 1
            if(k >= 0):
                maxi = max(maxi, r-l+1)
            r += 1
        return maxi
