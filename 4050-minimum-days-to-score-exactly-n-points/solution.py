class Solution:
    def minDays(self, n: int) -> int:

        scores = []

        streak, score = 1,1

        dp = [float("inf")] * (n + 1)

        while score <= n:
            scores.append(score)

            dp[score] = streak

            if score == n:
                return streak

            streak += 1

            score = (streak * (streak + 1)) // 2

        for num in range(2,n + 1):
            for score in scores:
                if score > num:
                    break
                
                dp[num] = min(dp[num],dp[num - score] + dp[score] + 1)

        return dp[n]