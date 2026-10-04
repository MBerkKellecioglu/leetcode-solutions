class Solution:
    def minFallingPathSum(self, matrix: list[list[int]]) -> int:
        
        n = len(matrix)

        prev = matrix[0][:]

        for i in range(1,n):
            nxt = [float("inf")] * n

            for j in range(n):
                curr = matrix[i][j]

                if j - 1 >= 0:
                    nxt[j] = min(nxt[j], prev[j - 1] + curr)
                
                nxt[j] = min(nxt[j], prev[j] + curr)

                if j + 1 < n:
                    nxt[j] = min(nxt[j], prev[j + 1] + curr)
            
            prev = nxt[:]
        
        return min(prev)

