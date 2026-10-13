class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mpp = {}
        n = len(s)
        maxfreq = maxlen = l = r = 0
        while(r < n):
            mpp[s[r]] = mpp.get(s[r], 0) + 1
            maxfreq = max(maxfreq, mpp[s[r]])
            if((r-l+1) - maxfreq > k):
                mpp[s[l]] -= 1
                l += 1
            else:
                maxlen = max(maxlen, r-l+1)
            r += 1
        return maxlen