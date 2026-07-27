class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Follow Up solution is kinda confusing
        ordered = sorted(nums)

        n = len(nums)

        l = (n // 2) if n % 2 else (n // 2) - 1
        h = n - 1

        for i in range(len(nums)):
            if i % 2:
                nums[i] = ordered[h]
                h -= 1
            else:
                nums[i] = ordered[l]
                l -= 1