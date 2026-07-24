class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:

        nums = list(set(nums))
        
        maxi, n, ans = max(nums), len(nums), 0

        # normally its 2**k - 1 (for k = max.bit_len)
        max_xor = 2**maxi.bit_length() 

        pairs = set()

        uniques = [False] * max_xor

        for i in range(n):
            for j in range(i,n):
                pairs.add(nums[i] ^ nums[j])

        for num in nums:
            for p_res in pairs:
                if not uniques[num ^ p_res]:
                    ans += 1
                    uniques[num ^ p_res] = True

        return ans

