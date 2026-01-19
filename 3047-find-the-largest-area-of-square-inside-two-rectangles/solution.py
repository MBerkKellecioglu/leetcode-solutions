class Solution:
    def largestSquareArea(self, bl: List[List[int]], tr: List[List[int]]) -> int:

        n, ans = len(bl), 0

        def calculate(bl, tr, i, j):
            x1i, y1i = bl[i] # bottom x-y for first
            x2i, y2i = tr[i] # top x-y for first

            x1j, y1j = bl[j] # bottom x-y for second
            x2j, y2j = tr[j] # top x-y for second

            l = max(x1i, x1j) # left
            r = min(x2i, x2j) # right
            b = max(y1i, y1j) # bottom
            u = min(y2i, y2j) # upper

            width = r - l
            height = u - b

            if width >= 0 and height >= 0:
                side = min(width, height)

                return side * side
            
            return 0


        for i in range(n):
            for j in range(i + 1, n):
                ans = max(ans, calculate(bl, tr, i, j))

        return ans
