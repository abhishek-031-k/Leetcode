class Solution:
    def nextGreaterElements(self, nums: list[int]) -> list[int]:
        st = []
        n = len(nums)
        ans = [-1]*n
        for i in range(2*n-1, -1, -1):
            while(st and st[-1] <= nums[i%n]): 
                st.pop()
            if(i < n):
                if(st):
                    ans[i] = st[-1]
                else:
                    ans[i] = -1
            st.append(nums[i%n])
        return ans        