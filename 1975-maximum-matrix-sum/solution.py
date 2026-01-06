class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        
        ans, n = 0, len(matrix)

        negative, mini = 0, float("inf")

        for row in matrix:
            for num in row:
                if num < 0:
                    negative += 1
                
                mini = min(mini, abs(num))

                ans += abs(num)

        return ans - (mini * 2) if negative % 2 else ans 
        
