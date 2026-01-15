class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:

        # 2 means they were dead and they are alive now, -1 means they were alive and dead now

        dirs = [(-1, -1), (-1, 0), (-1, 1),
                ( 0, -1),          ( 0, 1),
                ( 1, -1), ( 1, 0), ( 1, 1)]

        n, m = len(board), len(board[0])

        for i in range(n):
            for j in range(m):
                alive, dead = 0, 0

                for y, x in dirs:
                    y += i
                    x += j

                    if 0 <= y <= n - 1 and 0 <= x <= m - 1:
                        alive += int(board[y][x] == 1 or board[y][x] == -1)
                        dead += int(board[y][x] == 0 or board[y][x] == 2)
                
                if board[i][j] == 0:
                    if alive == 3:
                        board[i][j] = 2
                else:
                    if alive != 2 and alive != 3:
                        board[i][j] = -1

        for i in range(n):
            for j in range(m):
                if board[i][j] == 2:
                    board[i][j] = 1
                elif board[i][j] == -1:
                    board[i][j] = 0

        return None