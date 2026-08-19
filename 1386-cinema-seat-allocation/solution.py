class Solution:
    def maxNumberOfFamilies(self, n: int, reserved: List[List[int]]) -> int:

        m, ans = len(reserved), n * 2

        rows = defaultdict(int)

        # 000 means left, middle, right blocks are available, 1 means occupied
        
        for i in range(m):
            row,col = reserved[i]

            if rows[row] == 7 or col == 1 or col == 10:
                continue
            elif rows[row] == 0:
                ans -= 1

            if col == 2 or col == 3:
                rows[row] |= 4
            elif col == 4 or col == 5:
                rows[row] |= 4
                rows[row] |= 2
            elif col == 6 or col == 7:
                rows[row] |= 2
                rows[row] |= 1
            elif col == 8 or col == 9:
                rows[row] |= 1

            if rows[row] == 7:
                ans -= 1
        
        return ans

