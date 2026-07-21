class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        
        remainder = defaultdict(int)

        ans = 0

        for hour in hours:
            remainder[hour % 24] += 1

        if remainder[12] != 0:
            ans += (remainder[12] * (remainder[12] - 1)) // 2
            remainder[12] = 0
        
        if remainder[0] != 0:
            ans += (remainder[0] * (remainder[0] - 1)) // 2
            remainder[0] = 0

        for i in range(1,12):
            ans += remainder[i] * remainder[24 - i]


        return ans