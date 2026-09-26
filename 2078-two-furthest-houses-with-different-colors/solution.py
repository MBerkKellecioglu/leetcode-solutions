class Solution:
    def maxDistance(self, colors: list[int]) -> int:
        
        idx = 1

        n, ans = len(colors), -1

        while idx < n:
            if colors[0] != colors[idx]:
                ans = max(ans, idx)
            
            idx += 1

        idx = n - 2

        while idx > -1:
            if colors[n - 1] != colors[idx]:
                ans = max(ans, n - 1 - idx)

            idx -= 1

        return ans
