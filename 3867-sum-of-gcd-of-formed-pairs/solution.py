class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        
        n, ans = len(nums), 0

        pre = [0] * n
        maxi = -1

        l, r = 0, n - 1

        def gcd(a,b):
            a, b = max(a,b), min(a,b)

            while b:
                a,b = b, a % b
            
            return a

        for i, num in enumerate(nums):
            maxi = max(maxi, num)
            pre[i] = gcd(maxi, num)
        
        pre.sort()

        while l < r:
            ans += gcd(pre[l], pre[r])

            l += 1
            r -= 1

        return ans