class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        intervals.sort(key = lambda x: x[1])
        last = float('-inf')
        count = 0
        for start, end in intervals:
            if(start >= last):
                count += 1
                last = end
        
        return len(intervals) - count
