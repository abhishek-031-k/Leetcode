class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        low = 0
        high = n*m-1
        while(high >= low):
            mid = low + (high - low)//2
            row = mid//m
            col = mid%m
            if(matrix[row][col] == target): return True
            elif(matrix[row][col] > target): high = mid-1
            else: low = mid+1
        return False