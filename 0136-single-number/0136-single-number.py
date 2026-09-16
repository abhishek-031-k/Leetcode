class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for it in nums:
            ans ^= it
        return ans