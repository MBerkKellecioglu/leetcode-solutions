class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        
        day, n = 0, len(days)

        dp = [float("inf")] * (n + 1)

        t_pass = [1,7,30]

        days.insert(0,0)

        dp[0] = 0
 
        for idx in range(n + 1):
            day = days[idx]
            for i in range(3):
                p = t_pass[i]
                cost = costs[i]
                before = idx - 1
                
                boundry = max(0,day - p + 1)
                flag = False

                while before >= 0:
                    if days[before] < boundry:
                        if not flag:
                            flag = True
                        else:
                            break

                    dp[idx] = min(dp[idx], dp[before] + cost)
                    before -= 1
     
        return dp[n]