class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        
        vertical = defaultdict(lambda: 0)

        MOD = 10**9 + 7

        ans, total_comb = 0, 0

        for x, y in points:
            vertical[y] += 1
            vertical[y] %= MOD

        for freq in vertical.values():
            combination = (freq * (freq - 1)) // 2 % MOD
            ans  = (ans + combination * total_comb) % MOD
            total_comb = (total_comb + combination) % MOD

        return ans