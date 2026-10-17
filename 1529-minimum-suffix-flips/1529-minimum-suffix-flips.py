class Solution:
    def minFlips(self, target: str) -> int:
        ans = 0
        if(target[0] == '1'):
            ans = 1
        for i in range(1, len(target)):
            if(target[i] != target[i-1]):
                ans += 1
        return ans