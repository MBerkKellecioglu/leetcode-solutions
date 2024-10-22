class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        
        n = len(nums)
        l = 0
        r = 0
        
        ans = 0

        while r < n:
            if not nums[r]:
                k -= 1
                if k < 0:
                    print(l, r)
                    ans = max(ans, r - l)
                    while k < 0 and l < n:
                        if not nums[l]:
                            k += 1
                        
                        l += 1
            r += 1

        ans = max(ans, r - l)
        
        return ans
