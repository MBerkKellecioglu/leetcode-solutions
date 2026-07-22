class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

        self.x_boundry = [x_center - radius, x_center + radius]
        self.y_boundry = [y_center - radius, y_center + radius]          

    def randPoint(self) -> List[float]:
        R = self.radius
        x = random.uniform(self.x_boundry[0], self.x_boundry[1])
        y = random.uniform(self.y_boundry[0], self.y_boundry[1])

        x_diff = (x - self.x_center)
        y_diff = (y - self.y_center)

        while x_diff*x_diff + y_diff*y_diff > R*R:
            x = random.uniform(self.x_boundry[0], self.x_boundry[1])
            y = random.uniform(self.y_boundry[0], self.y_boundry[1])

            x_diff = (x - self.x_center)
            y_diff = (y - self.y_center)

        return[x,y]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()