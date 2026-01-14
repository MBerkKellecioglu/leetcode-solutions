class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        
        min_vert, max_vert = float("inf"), float("-inf")

        for x, y, l in squares:
            min_vert = min(min_vert, y)
            max_vert = max(max_vert, y + l)

        while max_vert - min_vert > 1e-6:
            mid = (max_vert + min_vert) / 2
            low_sum, high_sum = 0, 0

            for x, y, l in squares:
                if mid >= y + l:
                    low_sum += l * l
                elif mid <= y:
                    high_sum += l * l
                else:
                    low_sum += l * (mid - y)
                    high_sum += l * (y + l - mid)

            if high_sum > low_sum:
                min_vert = mid
            else:
                max_vert = mid

        return min_vert
        