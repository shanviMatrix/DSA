class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()

        count = 0
        previous = intervals[0]

        for current in intervals[1:]:
            if current[0] < previous[1]:
                count += 1

                if current[1] < previous[1]:
                    previous = current
            else:
                previous = current

        return count