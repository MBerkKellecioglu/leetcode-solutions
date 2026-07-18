class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        
        n, m = len(grid), len(grid[0])

        values = []

        # Idea here is for every k we traverse the grid
        dp = [[[float("inf")]  * (k + 1) for _ in range(m)] for _ in range(n)]

        dp[0][0][0] = 0

        # Sorting values because for every i we can teleport to j (0 <= j < i)
        # According to the problem statement i corresponds to (i,j) and j corresponds to (x, y)
        # So values[i] = grid[i][j] and for every j (0 <= j < i): values[j] = grid[x][y] -> (grid[x][y] <= grid[i][j]) 
        val_groups = defaultdict(list)
        for y in range(n):
            for x in range(m):
                val_groups[grid[y][x]].append((y,x))
        
        # The reason we are using sorted_vals is there could be cells that has same values 
        # Since they can teleport to each other aswell we need to update their costs at the same time
        # Checking them using if statements and while loops could complicate the code
        # If problem statement was grid[x][y] < grid[i][j] we wouldnt have to do this
        sorted_vals = sorted(val_groups.keys(), reverse = True)

        # This is the base case where we did not use any teleportation
        for y in range(n):
            for x in range(m):
                if y - 1 > -1:
                    dp[y][x][0] = min(dp[y][x][0], dp[y - 1][x][0] + grid[y][x])
                if x - 1 > -1:
                    dp[y][x][0] = min(dp[y][x][0], dp[y][x - 1][0] + grid[y][x])
        
        for tp in range(1, k + 1):
            """
            From high value to low value we are keeping track of minimum cost so we can know the tp cost
            from jth cell from all higher value cells (for all i)
            """
            min_cost = float("inf")
            for val in sorted_vals:
                for y, x in val_groups[val]:
                    min_cost = min(min_cost, dp[y][x][tp - 1])

                for y, x in val_groups[val]:
                    dp[y][x][tp] = min(dp[y][x][tp], min_cost)
            
            # After teleportations walk the grid again 
            for y in range(n):
                for x in range(m):
                    if y - 1 > -1:
                        dp[y][x][tp] = min(dp[y][x][tp], dp[y - 1][x][tp] + grid[y][x])
                    if x - 1 > -1:
                        dp[y][x][tp] = min(dp[y][x][tp], dp[y][x - 1][tp] + grid[y][x])
        
        return min(dp[n - 1][m - 1])
