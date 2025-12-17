class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        
        total = defaultdict(int)

        ans, flag, MOD = 0, 0, 10**9 + 7

        print(44483665844754 % MOD)

        for num in nums:
            total[num] += 1

        curr = defaultdict(int)

        for mid in nums:
            out = mid * 2

            if out in curr:
                if out == 0:
                    flag = 1

                ans = ans + (curr[out] * (total[out] - curr[out] - flag)) % MOD
                flag = 0
                
            curr[mid] += 1

        return ans % MOD