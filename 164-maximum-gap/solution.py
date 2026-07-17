class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        
        # Bucket Sort with Pigeonhole Principle ?!?!??!?!?
        
        """
        Basically we are putting our numbers in buckets based on their distance to minimum value 
        of the array. The way we are putting these numbers in buckets ensures that the maximum gap between
        numbers does not belong to gap between numbers that are in the same bucket.

        Lets say B = maximum gap divided by total amount of gaps. Maximum gap between consecutive
        numbers can be at minimum B. We put numbers into buckets according to this rule and check
        gaps between buckets maximum and minimums. 
        """

        mini, maxi, n = min(nums), max(nums), len(nums)

        if n < 2:
            return 0

        bucket_size = max(1, (maxi - mini) // (n - 1))

        bucket_count = ((maxi - mini) // bucket_size) + 1

        buckets = [[float("inf"), float("-inf")] for _ in range(bucket_count)]

        ans = 0

        for num in nums:
            bucket_idx = (num - mini) // (bucket_size)

            buckets[bucket_idx][0] = min(buckets[bucket_idx][0], num)
            buckets[bucket_idx][1] = max(buckets[bucket_idx][1], num)

        prev_max = mini

        for i in range(bucket_count):
            if buckets[i][0] != float("inf"):
                ans = max(ans, buckets[i][0] - prev_max)
                prev_max = buckets[i][1]

        return ans
        
