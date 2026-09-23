class Solution:
    def longestSubsequence(self, nums: list[int], diff: int) -> int:
        
        n = len(nums)
        
        cache = defaultdict(int)
        
        ans = 1
        
        for i in range(n - 1, -1, -1):
            
            cache[nums[i]] = cache[nums[i] + diff] + 1
        
            ans = max(ans,cache[nums[i]])
            
        return ans
            