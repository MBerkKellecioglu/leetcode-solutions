class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:

        y = min(by2,ay2) - max(ay1,by1)
        x = min(bx2,ax2) - max(bx1,ax1)

        common = x * y if x >= 0 and y >= 0 else 0

        a = (ay2 - ay1) * (ax2 - ax1)
        b = (by2 - by1) * (bx2 - bx1)

        return a + b - common