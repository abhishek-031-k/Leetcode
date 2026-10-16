class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x < 0):
            return False
        s = str(x)
        n = len(s)
        for i in range(0, n//2):
            if(s[i] == s[n-1-i]):
                continue
            else:
                return False
        return True

