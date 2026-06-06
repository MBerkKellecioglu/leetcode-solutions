class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        
        first, last = -1, 0

        primes = [False] * 101

        def prime(num):
            if num == 1:
                return False

            for div in range(2, int(sqrt(num)) + 1):
                if num % div == 0:
                    return False

            primes[num] = True
            return True

        for i in range(len(nums)):
            if primes[nums[i]] or prime(nums[i]):
                last = i

                if first == -1:
                    first = i
    
        return last - first