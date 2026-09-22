class Solution:
    def maxScore(self, cardPoints: list[int], k: int) -> int:
        maxi = 0
        totalsum = 0
        n = len(cardPoints)
        for i in range(0, k):
            totalsum += cardPoints[i]
        maxi = max(maxi, totalsum)
        for i in range(k-1, -1, -1):
            totalsum -= cardPoints[i]
            totalsum += cardPoints[n-k+i]
            maxi = max(maxi, totalsum)
        return maxi