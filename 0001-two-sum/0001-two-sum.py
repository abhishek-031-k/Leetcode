class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mpp = {}
        for i in range(0, len(nums)):
            rem = target - nums[i]
            if rem in mpp:
                return [mpp[rem], i]
            mpp[nums[i]] = i    
        return []    