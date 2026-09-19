class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        
        # x1 < x2 and y1 < y2 for every rect
        closest_x = max(x1, min(xCenter, x2))
        closest_y = max(y1, min(yCenter, y2))

        diff_x = (xCenter - closest_x)
        diff_y = (yCenter - closest_y)

        dist = (diff_x**2) + (diff_y**2)

        return (radius**2) >= dist