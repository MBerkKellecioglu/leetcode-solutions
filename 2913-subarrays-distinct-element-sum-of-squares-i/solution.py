class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        
        n, ans = len(nums), 0

        for i in range(n):
            unique = set()
            for j in range(i,n):
                unique.add(nums[j])

                ans += len(unique)**2
        
        return ans

