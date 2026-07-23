class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        
        # If n >= 3 you can generate all numbers 2^k where k is bit length of n
        return 2**len(nums).bit_length() if len(nums) >= 3 else len(nums).bit_length()