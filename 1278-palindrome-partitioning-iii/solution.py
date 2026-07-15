class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        
        n = len(s)

        # number of characters to change to make palindrome
        palindrome = [[0] * n for _ in range(n)]

        part = k - 1

        dp = [[-1] * (part + 1) for _ in range(n)]

        for i in range(n - 1,-1,-1):
            for j in range(i,n):
                if s[i] == s[j]:
                    if i + 1 > j - 1:
                        palindrome[i][j] = 0
                    else:
                        palindrome[i][j] = palindrome[i + 1][j - 1]
                else:
                    palindrome[i][j] = palindrome[i + 1][j - 1] + 1
        

        def dfs(part, ind):
            if ind + 1 <= part:
                return float("inf")

            if part <= 0:
                return palindrome[0][ind]

            if dp[ind][part] != -1:
                return dp[ind][part]
            
            change = float("inf")

            for i in range(ind, part - 1, -1):
                change = min(change, dfs(part - 1, i - 1) + palindrome[i][ind])

            dp[ind][part] = change

            return change

        return dfs(part, n - 1)