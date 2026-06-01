class Solution:
    def minOperations(self, nums: List[int]) -> int:

        freqs = Counter(nums)

        ans = 0

        for freq in freqs.values():
            if freq == 1:
                return -1
            elif freq % 3 == 0:
                ans += (freq // 3)
            elif freq % 3 == 1:
                ans += ( (freq - 4) // 3) + 2
            else:
                ans += ((freq - 2) // 3) + 1

        return ans