class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:

        freq = defaultdict(list)

        ans = 0

        for idx,num in enumerate(nums):
            freq[num].append(idx)

        for num,indexes in freq.items():
            if len(indexes) == 3:
                if indexes[2] - indexes[1] == indexes[1] - indexes[0]:
                    ans += 1

        return ans