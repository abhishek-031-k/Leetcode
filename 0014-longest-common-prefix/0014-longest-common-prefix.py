class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        ans = ""
        n = len(strs)
        for i in range(0, len(strs[0])):
            ch = strs[0][i]
            for j in range(1, n):
                if(i >= len(strs[j]) or strs[j][i] != ch):
                    return ans
           
            ans += ch
        return ans