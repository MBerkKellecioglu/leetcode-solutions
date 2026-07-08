class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:

        n, MOD = len(s), 10**9 + 7

        non_zero = [0]
        ans = []
        pow10 = [1] * (n + 1)

        if(s[0] != "0"):
            non_zero.append(int(s[0]))

        index = [0] * (n + 1)
        pre = [0] * (n + 1)

        for i in range(1,len(s)):
            pow10[i] = (pow10[i - 1] * 10) % MOD

            if s[i] != "0":
                non_zero.append((non_zero[-1] * 10 + int(s[i])) % MOD)
            
            index[i] = index[i - 1] + (s[i - 1] != "0")
            pre[i] = (pre[i - 1] + int(s[i - 1])) % MOD
        
        pre[n] = pre[n - 1] + int(s[n - 1])
        index[n] = index[n - 1] + (s[-1] != "0")

        for l,r in queries:
            sl, sr = index[l], index[r + 1]

            sub = (non_zero[sr] - non_zero[sl] * pow10[sr - sl]) % MOD
            add = pre[r + 1] - pre[l]

            ans.append((sub * add) % MOD)

        return ans




            