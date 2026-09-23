class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        
        n = len(nums)

        prev = nums[0] + nums[1]

        ans = 1

        for i in range(2, n, 2):
            if i + 1 < n:
                curr = nums[i] + nums[i + 1]
            else:
                break
            
            if prev != curr:
                break
            
            ans += 1

        return ans