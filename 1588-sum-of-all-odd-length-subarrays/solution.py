class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        
        ans, n = 0,len(arr)

        for i in range(n):
            # total number of subarrays that have nums[i] 
            subarray = (i + 1) * (n - i)

            # odd number of subarrays of that spesific number
            odd_sub = (subarray + (subarray % 2)) // 2

            ans += (odd_sub) * arr[i]

        return ans

        