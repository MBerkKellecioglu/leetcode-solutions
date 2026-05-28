class Solution:
    def minimumLines(self, stockPrices: List[List[int]]) -> int:

        if len(stockPrices) <= 1:
            return 0
        
        stockPrices.sort()

        ans = len(stockPrices) - 1

        prev_dx = stockPrices[1][0] - stockPrices[0][0]
        prev_dy = stockPrices[1][1] - stockPrices[0][1]

        for i in range(1, len(stockPrices) - 1):
            x1,y1 = stockPrices[i]
            x2,y2 = stockPrices[i + 1]

            dx = x2 - x1
            dy = y2 - y1

            if prev_dy * dx == prev_dx * dy:
                ans -= 1
            
            prev_dx = dx
            prev_dy = dy

        return ans

