class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        
        n, ans = len(nums), -1

        if k == n:
            return max(nums)
        
        freq = dict(Counter(nums))

        first = nums[0] if freq[nums[0]] == 1 else -1
        last = nums[-1] if freq[nums[-1]] == 1 else -1

        if k == 1:
            for key, val in freq.items():
                if val == 1 and key > ans:
                    ans = key
        else:
            ans = max(first,last)

        return ans