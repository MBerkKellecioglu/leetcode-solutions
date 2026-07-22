n = (5 * 10**6) + 1

primes = []

def sieve(n):
    ifPrime = [True] * n

    ifPrime[0], ifPrime[1] = False, False

    for num in range(2, int(sqrt(n)) + 1):
        if ifPrime[num]:
            for num in range(num * num, n, num):
                ifPrime[num] = False
        
    for num in range(2, n):
        if ifPrime[num]:
            primes.append(num)
    
    return None

sieve(n)

class Solution:
    def countPrimes(self, n: int) -> int:

        return bisect_left(primes,n)   
        
        