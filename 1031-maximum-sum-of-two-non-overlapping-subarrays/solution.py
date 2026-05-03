class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        
        n, ans = len(nums), -1

        pre = [0 for i in range(n + 1)]

        for i in range(n):
            pre[i + 1] = pre[i] + nums[i]
        
        def helper(l1, l2, limit):
            bestLeft = pre[l1] - pre[0]
            ans = -1

            for i in range(l1, limit):
                currLeft = pre[i] - pre[i - l1]
                bestLeft = max(bestLeft, currLeft)
            
                currRight = pre[i + l2] - pre[i]

                ans = max(ans, currRight + bestLeft)
            
            return ans
        
        ans = max(ans, helper(firstLen, secondLen, n - secondLen + 1))
        ans = max(ans, helper(secondLen, firstLen, n - firstLen + 1))

        return ans