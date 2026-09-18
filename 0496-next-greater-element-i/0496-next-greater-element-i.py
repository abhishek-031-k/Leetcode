class Solution:
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        ans = []
        mpp = {}
        st = []
        n = len(nums2)
        for i in range(n-1, -1, -1):
            while(st and st[-1] < nums2[i]):
                st.pop()
            if(st):
                mpp[nums2[i]] = st[-1]
            else:
                mpp[nums2[i]] = -1
            st.append(nums2[i])
        
        m = len(nums1)    
        for i in range(0, m):
            ans.append(mpp[nums1[i]])
        return ans    