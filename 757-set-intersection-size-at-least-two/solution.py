class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        
        intervals.sort(key = lambda i: (i[1], -i[0]))

        p1, p2, ans = -1, -1, 0

        for interval in intervals:
            if p2 < interval[0]:
                ans += 2
                p1, p2 = interval[1] -1 , interval[1]
            elif p1 < interval[0]:
                ans += 1
                p1, p2 = p2, interval[1]

        return ans