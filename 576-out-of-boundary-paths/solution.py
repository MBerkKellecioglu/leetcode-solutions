class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
        directions = [[-1,0],[1,0],[0,-1],[0,1]]

        prev = [[0] * n for _ in range(m)]

        ans, MOD = 0, 10**9 + 7

        prev[startRow][startColumn] = 1

        for move in range(maxMove):
            nxt = [[0] * n for _ in range(m)]

            for y in range(m):
                for x in range(n):
                    if prev[y][x] == 0:
                        continue

                    for dy,dx in directions:
                        ny,nx = y + dy, x + dx

                        if 0 <= ny < m and 0 <= nx < n:
                            nxt[ny][nx] = (prev[y][x] + nxt[ny][nx]) % MOD
                        else:
                            ans = (ans + prev[y][x]) % MOD 

            prev = nxt[:]

        return ans
            