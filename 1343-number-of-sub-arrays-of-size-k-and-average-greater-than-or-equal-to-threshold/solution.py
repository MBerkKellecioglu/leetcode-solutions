class Solution:
    def numOfSubarrays(self, arr: list[int], k: int, threshold: int) -> int:
        
        n,l,r = len(arr),0,0

        ans, window_total = 0,0

        while r < n:
            window_total += arr[r]

            while r - l + 1 > k and l <= r:
                window_total -= arr[l]
                l += 1
            
            if r - l + 1 == k and window_total / k >= threshold:
                ans += 1
            
            r += 1
            
        return ans
                
