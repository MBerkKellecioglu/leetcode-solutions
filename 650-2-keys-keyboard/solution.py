class Solution:
    def minSteps(self, n: int) -> int:

        div = [1]

        dp = defaultdict(lambda : float("inf"))

        for d in range(2, (n // 2) + 1):
            if n % d == 0:
                div.append(d)

        div.append(n)

        dp[1] = 0

        for i in range(1, len(div)):
            num = div[i]
            for j in range(i - 1, -1, -1):
                d = div[j]

                if num % d == 0:
                    dp[num] = min(dp[num], (num // d) + dp[d])
                    
        return dp[n]