class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        
        root = complexity[0]

        ans, mult = 1, 1

        MOD = 10**9 + 7

        for c in complexity[1:]:
            if c > root:
                ans = (ans * mult) % MOD
                mult += 1
            else:
                return 0
        
        return ans