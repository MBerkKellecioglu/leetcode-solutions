class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        
        n, m = len(nums1), len(nums2)

        dp = [[float("-inf") for j in range(m + 1)] for i in range(n + 1)]

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                max1 = (nums1[i] * nums2[j]) + max(0, dp[i + 1][j + 1])
                max2 = dp[i + 1][j]
                max3 = dp[i][j + 1]

                dp[i][j] = max(max1, max2, max3)
        
        return dp[0][0]

