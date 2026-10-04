class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        
        total = 0

        # Kadane
        max_sum, curr_max = float("-inf"), 0

        # finding min sum in the array to maximize circular sum
        min_sum, curr_min = float("inf"), 0

        for num in nums:
            total += num

            curr_max = max(num, curr_max + num)
            max_sum = max(max_sum, curr_max)

            curr_min = min(num, curr_min + num)
            min_sum = min(min_sum, curr_min)
        
        
        if max_sum < 0:
            return max_sum

        return max(max_sum, total - min_sum)

