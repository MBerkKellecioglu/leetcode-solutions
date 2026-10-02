primes = [2]

num = 3

while primes[-1] <= 1000:
    prime = True

    for n in range(2,int(sqrt(num)) + 1):
        if num % n == 0:
            prime = False
            break
        
    if prime:
            primes.append(num)
        
    num += 1
        
class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        
        idx = bisect_left(primes,nums[0]) - 1
    
        if idx >= 0:
            nums[0] -= primes[idx]

        for i in range(1, len(nums)):
            diff = nums[i] - nums[i - 1]

            if diff <= 0:
                return False

            idx = bisect_left(primes,diff) - 1

            if idx >= 0:
                nums[i] -= primes[idx]
        
        return True
        