class Solution:
    def countDigitOne(self, n: int) -> int:
        
        dp = {}

        s = str(n)

        def dfs(idx,count,limit):
            nonlocal s

            if idx == len(s):
                return count

            if not limit and (idx,count) in dp:
                return dp[(idx,count)]

            boundry = int(s[idx]) if limit else 9

            ans = 0

            for b in range(boundry + 1):
                next_limit = limit and (b == boundry)
                next_count = count + int(b == 1)
                ans += dfs(idx + 1, next_count, next_limit)

            if not limit:
                dp[(idx, count)] = ans

            return ans
        
        return dfs(0,0,True)
            

