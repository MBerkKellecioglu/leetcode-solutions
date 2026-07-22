primes = []

n = 10**6 + 1

def sieve(n):
    ifPrime = [True] * n 
    ifPrime[0], ifPrime[1] = False, False

    for num in range(2, int(sqrt(n)) + 1):
        if ifPrime[num]:
            for mul in range(num * num, n, num):
                ifPrime[mul] = False

    for num in range(n):
        if ifPrime[num]:
            primes.append(num)
    
    return None

sieve(n)

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        
        closest_idx = bisect_left(primes, left)

        min_diff = float("inf")
        idx = -1

        while closest_idx + 1 < len(primes) and primes[closest_idx + 1] <= right:
            diff = primes[closest_idx + 1] - primes[closest_idx]

            if min_diff > diff:
                idx = closest_idx
                min_diff = diff

            closest_idx += 1

        return [primes[idx], primes[idx + 1]] if idx != -1 else [-1,-1]