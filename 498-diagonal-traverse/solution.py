class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        
        row, col = len(mat), len(mat[0])

        reverse = True

        ans = []

        for c in range(col):
            y,x = 0,c
            
            diag = []

            while 0 <= x and y < row:
                diag.append(mat[y][x])
                x -= 1
                y += 1

            if reverse:
                diag.reverse()
            
            reverse ^= 1

            ans += diag
        
        for r in range(1, row):
            y, x = r, col - 1

            diag = []

            while 0 <= x and y < row:
                diag.append(mat[y][x])
                x -= 1
                y += 1
            
            if reverse:
                diag.reverse()

            reverse ^= 1

            ans += diag

        return ans
