class Solution:
    def kidsWithCandies(self, candies: List[int], ex: int) -> List[bool]:
        
        maxi = max(candies)

        ans = []

        for c in candies:
            if c + ex  >= maxi:
                ans.append(True)
            else:
                ans.append(False)

        return ans