class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        
        l, n, ans = 0, len(prices), 0 

        while l < n:
            r = l + 1

            while r < n and prices[r - 1] - prices[r] == 1:
                r += 1

            dist = r - l
            ans += (dist * (dist + 1)) // 2

            l = r
        
        return ans

