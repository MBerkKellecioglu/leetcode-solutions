class Solution:
    def rotateElements(self, nums: List[int], k: int) -> List[int]:

        pos = []
        vals = []

        for i, x in enumerate(nums):
            if x >= 0:
                pos.append(i)
                vals.append(x)

        n = len(vals)

        for i in range(n):
            nums[pos[(i - k) % n]] = vals[i]

        return nums