class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        
        maxi, ans = 0, 0
        
        for i in range(len(flips)):
            maxi = max(maxi, flips[i])

            if maxi == i + 1:
                ans += 1
            

        return ans
