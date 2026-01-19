class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        
        l, r, ans = 1, (2 * (10**9) + 1), float("inf")

        exc = [-1] * 4

        def lcm(a,b):
            return a * b // gcd(a,b)

        exc[0], exc[1], exc[2], exc[3] = lcm(a,b), lcm(a,c), lcm(b,c), lcm(lcm(a,b),c)

        # exc means exclude (cluster)
        # numbers that are divisible a,b and c (index 3) are included actually but was too lazy to name otherwise

        print(self.countUgly(7, a, b, c, exc))

        while l <= r:
            mid = (l + r) // 2

            res = self.countUgly(mid,a,b,c,exc)

            if res < n:
                l = mid + 1
            elif res >= n:
                r = mid - 1

                if res == n:
                    ans = min(ans, res)

        return l

    def countUgly(self, mid: int, a: int, b: int, c: int, exc: list):
            n = 0

            n += (mid // a) + (mid // b) + (mid // c) + (mid // exc[3])

            n -= (mid // exc[0]) + (mid // exc[1]) + (mid // exc[2])

            return n

            


    

