class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        
        x = int(k**0.5)

        balance_remainder = defaultdict(int)

        balance_remainder[(0,0)] += 1

        while 1:
            if (x * x) % k == 0:
                break
            x += 1

        ans, MOD, balance = 0, 2*x, 0
     
        for i, c in enumerate(s):
            remainder = (i + 1) % MOD

            if c in "aeiou":
                balance += 1
            else:
                balance -= 1

            key = (balance,remainder)

            ans += balance_remainder[key]
            
            balance_remainder[key] += 1
        
        return ans