class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        
        total,n = sum(nums),len(nums)

        if total % k:
            return False
        
        sub = [total // k] * k

        if max(nums) > sub[0]:
            return False

        dp = {}

        def dfs(mask, idx):
            if mask == (1 << n) - 1:
                return True

            if mask in dp:
                return dp[mask]

            for i in range(n):
                if (mask & (1 << i)) == 0:
                
                    if sub[idx] - nums[i] >= 0:
                        sub[idx] -= nums[i]

                        if dfs(mask | (1 << i), idx + (sub[idx] == 0)):
                            dp[mask] = True
                            return True
                        
                        sub[idx] += nums[i]
            
            dp[mask] = False
            return dp[mask]

        return dfs(0,0)