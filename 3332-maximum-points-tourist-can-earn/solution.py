class Solution:
    def maxScore(self, cities: int, days: int, stayScore: List[List[int]], travelScore: List[List[int]]) -> int:
         
        dp = [[0 for i in range(cities)] for j in range(days + 1)]

        for day in range(days):
            for curr in range(cities):
                dp[day + 1][curr] = max(dp[day + 1][curr], dp[day][curr] + stayScore[day][curr])

                for dest in range(cities):
                    if curr != dest:
                        dp[day + 1][curr] =  max(dp[day + 1][curr], dp[day][dest] + travelScore[dest][curr])


        return max(dp[days])
