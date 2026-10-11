class Solution:
    def minGroups(self, intervals: list[list[int]]) -> int:
        left = []
        right = []
        for start,end in intervals:
            left.append(start)
            right.append(end)
        left.sort()
        right.sort()
        count = 0
        temp = 0
        i = 0
        j = 0
        n = len(intervals)
        while(i < n and j < n):
            if(left[i] <= right[j]):
                temp += 1
                i += 1
            else:
                temp -= 1
                j += 1
            count = max(temp, count)
        return count