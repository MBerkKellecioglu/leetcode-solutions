class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        
        m = len(primes)

        ugly = [1] * (n)

        pointers = [0] * m

        nxt_val = [i for i in primes]

        for i in range(1, n):
            nxt = min(nxt_val)
            ugly[i] = nxt

            for j in range(m):
                if nxt == nxt_val[j]:
                    pointers[j] += 1
                    nxt_val[j] = primes[j] * ugly[pointers[j]]
        
        return ugly[n - 1]
