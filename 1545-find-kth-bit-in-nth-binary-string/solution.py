class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        
        def helper(n, k):
            if n == 1:
                return 0

            mid = 2**(n - 1)

            if k == mid:
                return 1
            elif k < mid:
                return helper(n - 1, k)
            else:
                return 1 ^ helper(n - 1, (2*mid) - k)

        return str(helper(n, k))