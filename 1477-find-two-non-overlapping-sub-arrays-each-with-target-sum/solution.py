class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        
        n = len(arr)

        min_len = [float("inf")] * n 

        l, r = 0,0

        curr_sum, ans = 0, float("inf")

        while r < n:
            curr_sum += arr[r]
            curr_len = float("inf")

            while l <= r and curr_sum > target:
                curr_sum -= arr[l]
                l += 1
            
            if curr_sum == target:
                curr_len = (r - l + 1)

                if l - 1 > -1:
                    ans = min(ans, curr_len + min_len[l - 1])

            min_len[r] = min(min_len[r - 1], curr_len)

            r += 1
        
        return ans if ans != float("inf") else -1