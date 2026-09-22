class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        arr = [-1] * 255
        l = 0
        r = 0
        maxlen = 0
        while(r < len(s)):
            if(arr[ord(s[r])] != -1):
                if(arr[ord(s[r])] >= l):  l = arr[ord(s[r])] + 1

            maxlen = max(maxlen, r - l + 1)
            arr[ord(s[r])] = r
            r += 1
        return maxlen