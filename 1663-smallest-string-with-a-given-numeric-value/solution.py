class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        
        ans = ""

        for i in range(1, n + 1):
            x = max(k - (n - i) * 26, 1)

            ans += chr(x + ord('a') - 1)

            k -= x
        
        return ans
            