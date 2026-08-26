class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        
        n, ans = len(stones), float("-inf")

        prefix = [0] * n

        prefix[1] = stones[0] + stones[1]

        for i in range(2, n):
            prefix[i] = prefix[i - 1] + stones[i]

        ans = prefix[-1]

        for i in range(n - 2, 0, -1):
            ans = max(ans, prefix[i] - ans)

        return ans