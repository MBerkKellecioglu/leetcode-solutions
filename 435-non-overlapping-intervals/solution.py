class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:

       intervals.sort()

       ind = 0
       sol = 0

       maxi = intervals[0][1]

       print(intervals)

       for ind in range(len(intervals) - 1):

            if maxi <= intervals[ind + 1][0]:
                maxi = intervals[ind + 1][1]
            else:
                maxi = min(maxi, intervals[ind + 1][1])
                
                sol += 1

                
       return sol