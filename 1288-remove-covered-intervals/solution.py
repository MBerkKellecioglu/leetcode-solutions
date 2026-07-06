class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        
        intervals.sort()

        n, ans = len(intervals), len(intervals)

        maxi = intervals[0][1]

        deleted = [False] * n

        for i in range(1, n):
            curr_min, curr_max = intervals[i]
            
            if curr_max <= maxi:
                deleted[i] = True
                ans -= 1
            else:
                maxi = curr_max
                if curr_min == intervals[i - 1][0] and not deleted[i - 1]:
                    ans -= 1
                    deleted[i - 1] = True
                           
        return ans