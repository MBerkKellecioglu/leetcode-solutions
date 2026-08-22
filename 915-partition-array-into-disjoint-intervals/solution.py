class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        
        n = len(nums)

        suffix = [float("inf")] * n

        suffix[-1] = nums[-1]

        maxi = float("-inf")

        for i in range(n - 2, 0, -1):
            suffix[i] = min(nums[i], suffix[i + 1])

        for i in range(n - 1):
            maxi = max(nums[i], maxi)

            if maxi <= suffix[i + 1]:
                return i + 1

        return -1
