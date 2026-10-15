class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(0 , n):
            st = set()
            for j in range(i, n):
                st.add(nums[j])
                dis = len(st)
                ans += dis**2
        return ans
