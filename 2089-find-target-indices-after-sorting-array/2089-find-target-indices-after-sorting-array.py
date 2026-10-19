class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        ans = []
        low = 0
        high = len(nums)-1
        while(low <= high):
            mid = low + (high - low)//2
            if(nums[mid] >= target):
                high = mid - 1
            else:
                 low = mid + 1
        while(low < len(nums) and nums[low] == target):
            ans.append(low)
            low += 1
        return ans