class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        
        n, MOD = len(board), 10**9 + 7

        dp = [[[float("-inf"),0] for i in range(n)]for j in range(n)]

        dp[n - 1][n - 1] = [0, 1]

        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if board[i][j] == "X" or (i == n - 1 and j == n - 1):
                    continue

                directions = [(i + 1, j), (i, j + 1), (i + 1, j + 1)]                

                score = float("-inf")
                path = 0

                val = int(board[i][j]) if board[i][j] != "E" else 0

                for r, c in directions:
                    if r < n and c < n and dp[r][c][0] != float("-inf"):
                        prev_score = dp[r][c][0]
                        prev_path = dp[r][c][1]

                        if prev_score > score:
                            score = prev_score
                            path = prev_path
                        elif prev_score == score:
                            path = (path + prev_path) % MOD  
                    
                    if score != float("-inf"):
                        dp[i][j][0] = score + val
                        dp[i][j][1] = path


        return dp[0][0] if dp[0][0][0] != float("-inf") else [0,0]
                    


    