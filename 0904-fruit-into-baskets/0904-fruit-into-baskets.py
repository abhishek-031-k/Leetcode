class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        maxi = r = l = 0
        mpp = {}
        n = len(fruits)
        while(r < n):
            mpp[fruits[r]] = mpp.get(fruits[r], 0) + 1
            if(len(mpp) > 2):
                mpp[fruits[l]] -= 1
                if(mpp[fruits[l]] == 0):
                    del mpp[fruits[l]]
                l += 1
            if(len(mpp) <= 2):
                maxi = max(maxi, r-l+1)
            r += 1
        return maxi

