class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        
        n = len(nums)
        total = sum(nums)

        possible_lengths = []

        # sum(arr) // len(arr) = sum(nums) // len(nums)
        # that means sum(nums) * len(arr) // len(nums) = sum(arr)
        # sum(arr) cant be a float number so sum(nums) * len(arr) % len(nums) == 0

        for l in range(1, (n // 2) + 1):
            if (total * l) % n == 0:
                possible_lengths.append(l)

        dp = [0] * ((n // 2) + 1)
        dp[0] = 1

        # dp keeps info on every total that can be obtained for lengths between 1 to n // 2 + 1
        # for example dp[2] has every possible total for 2 any elements of the array
        # we are keeping the info with bitmask (nth bit means n total can be obtained)

        for num in nums:
            for i in range(n // 2, 0, -1):
                dp[i] |= (dp[i - 1] << num)

        
        for l in possible_lengths:
            target = (total * l) // n

            mask = 1 << target

            if dp[l] & mask:
                return True

        return False
