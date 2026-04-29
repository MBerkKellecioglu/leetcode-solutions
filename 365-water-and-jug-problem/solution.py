class Solution:
    def canMeasureWater(self, cx: int, cy: int, target: int) -> bool:
        
        dp = [[0 for i in range(cx + 1)] for j in range(cy + 1)]

        def dfs(x, y, target):
            if x + y == target:
                return True
            
            if dp[y][x]:
                return False
            
            dp[y][x] = 1

            # Empty bottles
            if x != 0 and dfs(0, y, target):
                return True
            if y != 0 and dfs(x, 0, target):
                return True

            # Fill bottles
            if x != cx and  dfs(cx, y, target):
                return True 
            if y != cy and dfs(x, cy, target):
                return True

            # Fill bottles w eachother
            if dfs(min(cx, x + y), max(y - (cx - x), 0), target):
                return True
            if dfs(max(x - (cy - y), 0), min(cy, y + x), target):
                return True
            
            return False

        return dfs(0, 0, target)