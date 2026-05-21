class Solution:
    def minDifference(self, nums: List[int], q: List[List[int]]) -> List[int]:
        
        n, m = len(nums), len(q)

        dp = [[0 for i in range(101)] for j in range(n + 1)]

        ans = []

        for i in range(n):
            dp[i + 1] = dp[i][:]
            dp[i + 1][nums[i]] += 1

        for i in range(m):
            l, r = q[i]
            prev = -1
            mini = float("inf")
            for x in range(1, 101):
                freq = dp[r + 1][x] - dp[l][x] 

                if freq > 0:
                    if prev != -1:
                        mini = min(mini, x - prev)
                
                    prev = x
            
            ans.append(mini if mini != float("inf") else -1)

        return ans


