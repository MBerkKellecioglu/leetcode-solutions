class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        
        turn = minutesToTest // minutesToDie

        pigs = 0

        while True:
            if (turn + 1)**pigs >= buckets:
                return pigs

            pigs += 1
        
        return -1