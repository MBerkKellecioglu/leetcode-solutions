class Solution:
    def findPeakGrid(self, mat: list[list[int]]) -> list[int]:
        
        m,n = len(mat), len(mat[0])

        up,down = 0, m - 1

        while up <= down:
            mid = (up + down) // 2

            maxi = max(mat[mid])

            idx = mat[mid].index(maxi)

            if mid + 1 < m and maxi < mat[mid + 1][idx]:
                up = mid + 1
                continue
            
            if mid - 1 >= 0 and maxi < mat[mid - 1][idx]:
                down = mid - 1
                continue
            
            return [mid,idx]
        
        return [-1,-1]

            