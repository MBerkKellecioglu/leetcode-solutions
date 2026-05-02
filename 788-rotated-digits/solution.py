class Solution:

    dp = [-1 for i in range(10**4 + 1)]

    def rotatedDigits(self, n: int) -> int:

        ans = 0

        self.dp[0] = 0
        
        for num in range(n + 1):
            # -1 means not checked, 0 means bad, 1 means good, 2 means invalid
            if self.dp[num] != -1:
                ans += (self.dp[num] == 1)
            else:
                rest = num // 10
                last = num % 10

                if self.dp[rest] == 2 or str(last) in "347":
                    self.dp[num] = 2
                elif str(last) in "2569":
                    self.dp[num] = 1
                else:
                    self.dp[num] = self.dp[rest]

                ans += (self.dp[num] == 1)
        
        return ans


