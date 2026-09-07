class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        
        n = len(nums)

        heap = [(nums[0], 0)]

        dp = [float("-inf")] * n

        dp[0] = nums[0]

        for i in range(1, n):
            while heap and heap[0][1] < i - k:
                heappop_max(heap)

            dp[i] = nums[i] + max(0,heap[0][0])

            heappush_max(heap, (dp[i], i))

        return max(dp)

        
