class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        
        # for every a,b,c there is b,a,c which ((a | b) & c) ^ ((b | a) & c) = 0
        # so we look at pairs and for every a,b there is b,a
        # and we understand we only need to look a,a,a which means a
        # therefore XOR all values

        ans = 0

        for num in nums:
            ans ^= num

        return ans