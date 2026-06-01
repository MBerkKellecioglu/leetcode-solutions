class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        

        cost.sort(reverse=True)

        ans, flag = 0, 0 

        for i in range(len(cost)):
            if (flag % 3) != 2:
                ans += cost[i]
            
            flag += 1
            flag %= 3
                
        

        return ans