class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        
        n = len(nums)

        diff = [0 for i in range(2* limit + 2)]

        for i in range(n // 2):
            a = nums[i]
            b = nums[n - i - 1]

            if a > b:
                a, b = b, a

            diff[2] += 2
            diff[2 * limit + 1] -= 2

            diff[a + 1] -= 1
            diff[b + limit + 1] += 1

            diff[a + b] -= 1
            diff[a + b + 1] += 1
        
        curr, ans = 0, float("inf")

        for i in range(2, 2 * limit + 1):
            curr += diff[i]
            ans = min(ans, curr)

        return ans