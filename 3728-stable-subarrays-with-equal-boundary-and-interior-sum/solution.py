class Solution:
    def countStableSubarrays(self, cap: List[int]) -> int:
        
        n, ans = len(cap), 0

        checked = defaultdict(int)

        prefix = [0 for i in range(n + 1)]

        for i in range(1, n + 1):
            prefix[i] = prefix[i - 1] + cap[i - 1]

        for r in range(2, n):
            l = r - 2

            checked[(cap[l], cap[l] + prefix[l + 1])] += 1

            ans += checked[(cap[r], prefix[r])]

        return ans
