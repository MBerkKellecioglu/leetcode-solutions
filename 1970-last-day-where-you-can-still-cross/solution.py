class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        
        n, ans = len(cells), float("inf")

        l, r = 0, n - 1

        land = [[0 for i in range(col)] for j in range(row)]

        prev_mid = 0

        while l <= r:
            mid = (l + r) // 2
            checked = [[0 for i in range(col)] for j in range(row)]
            cross = False

            if prev_mid < mid:
                for i in range(prev_mid, mid):
                    y, x = cells[i]
                    land[y - 1][x - 1] = 1
            else:
                for i in range(mid, prev_mid):
                    y, x = cells[i]
                    land[y - 1][x - 1] = 0
            
            prev_mid = mid

            q = deque()

            for i in range(col):
                if not land[0][i]:
                    q.append([0,i])

            while q:
                i, j = q.popleft()

                if i + 1 == row:
                    ans = mid
                    cross = True
                    break

                if i + 1 < row and not land[i + 1][j] and not checked[i + 1][j]:
                    checked[i + 1][j] = 1
                    q.append([i + 1, j])
                
                if i - 1 > -1 and not land[i - 1][j] and not checked[i - 1][j]:
                    checked[i - 1][j] = 1
                    q.append([i - 1, j])

                if j + 1 < col and not land[i][j + 1] and not checked[i][j + 1]:
                    checked[i][j + 1] = 1
                    q.append([i, j + 1])

                if j - 1 > -1 and not land[i][j - 1] and not checked[i][j - 1]:
                    checked[i][j - 1] = 1
                    q.append([i, j - 1])

            if cross:
                l = mid + 1
            else:
                r = mid - 1

        return ans

            