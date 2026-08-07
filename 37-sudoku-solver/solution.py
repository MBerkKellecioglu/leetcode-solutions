class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [0] * 9
        cols = [0] * 9
        squares = [0] * 9

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    mask = 1 << int(board[i][j])
                    square = (i // 3) * 3 + (j // 3)

                    rows[i] |= mask
                    cols[j] |= mask
                    squares[square] |= mask


        def dfs(idx):
            if idx == 81:
                return True

            row,col = (idx // 9), (idx % 9)
            square = (row // 3) * 3 + (col // 3)

            if board[row][col] != '.':
                return dfs(idx + 1)
            else:
                for digit in range(1,10):
                    mask = (1 << digit)

                    if not (rows[row] & (mask)) and not (cols[col] & mask) and (not squares[square] & mask):
                        rows[row] |= mask
                        cols[col] |= mask
                        squares[square] |= mask

                        board[row][col] = str(digit)

                        if dfs(idx + 1):
                            return True

                        rows[row] &= ~(mask)
                        cols[col] &= ~(mask)
                        squares[square] &= ~(mask)

                        board[row][col] = "."

        dfs(0)
