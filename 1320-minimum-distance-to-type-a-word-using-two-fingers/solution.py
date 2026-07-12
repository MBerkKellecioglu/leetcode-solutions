class Solution:
    def minimumDistance(self, word: str) -> int:

        n = len(word)

        # 26th index means our other hand is free
        dp = [[float("inf") for _ in range(27)] for _ in range(n)]

        dp[0][26] = 0

        def dist(l1, l2):
            if l1 == 26 or l2 == 26:
                return 0
            
            x1, y1 = l1 % 6, l1 // 6
            x2, y2 = l2 % 6, l2 // 6

            return abs(x1 - x2) + abs(y1 - y2)

        for i in range(1, n):
            curr = ord(word[i]) - ord('A')
            prev = ord(word[i - 1]) - ord('A')

            for letter in range(27):
                if dp[i - 1][letter] == float("inf"):
                    continue
                
                cost1 = dp[i - 1][letter] + dist(prev, curr)
                dp[i][letter] = min(cost1, dp[i][letter])

                cost2 = dp[i - 1][letter] + dist(letter,curr)
                dp[i][prev] = min(cost2, dp[i][prev])         
        
        return min(dp[n - 1])