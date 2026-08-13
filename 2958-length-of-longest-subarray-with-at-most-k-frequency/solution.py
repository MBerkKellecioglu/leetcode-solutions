class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        
        ans, l = 0, 0

        freq = defaultdict(int)

        for r in range(len(nums)):
            num = nums[r]
            freq[num] += 1

            if freq[num] > k:
                while freq[num] > k:
                    freq[nums[l]] -= 1
                    l += 1
            
            ans = max(ans, r - l + 1)

        return ans

