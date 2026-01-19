class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        
        l, r = min(nums), max(nums)

        ans = float("inf")

        def minCap(nums, mid, k):
            n = len(nums)
            i = 0

            while i < n:
                if nums[i] <= mid:
                    k -= 1
                    i += 2
                else:
                    i += 1

            return bool(k <= 0)


        while l <= r:
            mid = (l + r) // 2

            if minCap(nums, mid, k):
                ans = min(ans, mid)
                r = mid - 1
            else:
                l = mid + 1
        
        return ans