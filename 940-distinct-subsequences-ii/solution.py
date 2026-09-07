class Solution:
    def distinctSubseqII(self, s: str) -> int:
        
        alpha = [0] * 26 # for every character number of subsequences that ends with that character

        total = 0

        MOD = 10**9 + 7

        for c in s:
            idx = ord(c) - ord('a')

            subs = (total + 1) % MOD # number of all subs that ends with current character currently

            distinct = (subs - alpha[idx]) # number of distinct subs that end with current character currently

            total = (total + distinct) % MOD

            alpha[idx] = subs

        return total

            