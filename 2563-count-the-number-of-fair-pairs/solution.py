class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        
        n, ans = len(nums),0

        nums.sort()

        l, r = n - 1, n - 1

        for i in range(n):
            while r > i and nums[r] + nums[i] > upper:
                r -= 1

            if r <= i:
                break

            while l > i and nums[i] + nums[l] >= lower:
                l -= 1
            
            start = max(i + 1, l + 1)
            end = r

            if start <= end:
                ans += end - start + 1

        return ans


  