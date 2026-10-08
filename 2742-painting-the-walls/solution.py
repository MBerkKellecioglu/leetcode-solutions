class Solution:
    def paintWalls(self, cost: list[int], time: list[int]) -> int:

        n = len(cost)

        dp = [float("inf")] * (n + 1)

        dp[0] = 0

        for c,t in zip(cost,time):
            for total_wall in range(n, 0, -1):
                # current time + 1 coverage
                walls_covered_before = max(0, total_wall - (t + 1))
                use_curr_wall = dp[walls_covered_before] + c

                # skip current wall
                skip_curr_wall = dp[total_wall]

                dp[total_wall] = min(skip_curr_wall, use_curr_wall)
        
        return dp[n]

