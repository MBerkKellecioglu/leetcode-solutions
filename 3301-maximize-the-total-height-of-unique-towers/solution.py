class Solution:
    def maximumTotalSum(self, h: List[int]) -> int:
        
        # [2,3,4,3] -> we can select max numbers for each element because no number can repeat
        # 10,7,7,7,7,-> 
        # 4,3,3,2

        h.sort(reverse=True)

        maxi, ans, n = h[0], h[0], len(h)

        for i in range(1,n):
            if h[i] < maxi:
                ans += h[i]
                maxi = h[i]
            else:
                maxi -= 1
                while maxi > 0 and h[i] <= maxi:
                    maxi -= 1

                if maxi == 0:
                    return -1
                
                ans += maxi
        
        return ans

