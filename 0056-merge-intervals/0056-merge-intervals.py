class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        ans = []
        if(len(intervals) == 0):
            return ans
        intervals.sort()
        temp = [intervals[0][0], intervals[0][1]]
        for start, end in intervals:
            if(start <= temp[1]):
                temp[1] = max(temp[1], end)
            else:
                ans.append(temp)
                temp = [start, end]
        ans.append(temp)
        return ans
