class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        temp = start ^ goal
        count = 0
        for i in range(0, 31):
            if(temp & (1 << i)):
                count += 1
        return count    