class Solution:

    def leftmax(self, n: int, left: list[int], height: list[int]):
       left[0] = height[0]
       for i in range(1, n):
        left[i] = max(left[i-1], height[i])

    def rightmax(self, n: int, right: list[int], height: list[int]):
       right[n-1] = height[n-1]
       for i in range(n-2, -1, -1):
        right[i] = max(right[i+1], height[i])

    def trap(self, height: list[int]) -> int:
        n = len(height)
        left = [-1]*n
        right = [-1]*n
        self.leftmax(n, left, height)
        self.rightmax(n, right, height)
        ans = 0
        for i in range(0, n):
            ans += min(left[i], right[i]) - height[i]
        return ans