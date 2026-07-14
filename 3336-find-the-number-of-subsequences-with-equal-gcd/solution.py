class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        
        n, maxi, ans = len(nums), max(nums), 0 

        MOD = 10**9 + 7

        def gcd(a, b):
            a, b = max(a,b), min(a,b)

            while b:
                a, b = b, a % b
            
            return a

        dp = [[[0 for _ in range(maxi + 1)] for _ in range(maxi + 1)] for _ in range(n + 1)]

        dp[0][0][0] = 1

        for i in range(n):
            num = nums[i]
            for g1 in range(maxi + 1):
                for g2 in range(maxi + 1):
                    if dp[i][g1][g2] == 0:
                        continue
                    
                    curr_total = dp[i][g1][g2]
                    
                    #skip
                    dp[i + 1][g1][g2] = (dp[i + 1][g1][g2] + curr_total) % MOD

                    # add to first sequence
                    dp[i + 1][gcd(g1,num)][g2] = (dp[i + 1][gcd(g1, num)][g2] + curr_total) % MOD
                    
                    # add to second sequence
                    dp[i + 1][g1][gcd(g2,num)] = (dp[i + 1][g1][gcd(g2,num)] + curr_total) % MOD

        for g in range(1, maxi + 1):
            ans = (ans + dp[n][g][g]) % MOD

        return ans