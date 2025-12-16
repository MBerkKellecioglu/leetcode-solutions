class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        
        checked = defaultdict(lambda : - 1)

        buildings.sort()

        n, i = len(buildings), 0

        while i < n:
            x, y = buildings[i]
            last_y = y

            while i + 1 < n and x == buildings[i + 1][0]:
                checked[(x, last_y)] += 1
                i += 1
                last_y = buildings[i][1]

            checked[(x,y)] -= 1
            i += 1

        buildings.sort(key= lambda x : x[1])

        i = 0

        while i < n:
            x, y = buildings[i]
            last_x = x

            while i + 1 < n and y == buildings[i + 1][1]:
                checked[(last_x, y)] += 1
                i += 1
                last_x = buildings[i][0]

            checked[(x,y)] -= 1
            i += 1

        ans = 0

        for v in checked.values():
            if v > 0:
                ans += 1

        return ans