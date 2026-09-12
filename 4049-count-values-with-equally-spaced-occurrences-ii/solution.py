class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:

        freq = defaultdict(list)

        ans = 0

        for idx,num in enumerate(nums):
            if len(freq[num]) < 2:
                freq[num].append(idx)
            else:
                if idx - freq[num][-1] == freq[num][1] - freq[num][0]:
                     freq[num].append(idx)
                else:
                    freq[num] = [float("inf")]
        
        for num,indexes in freq.items():
            if len(indexes) >= 3:
                ans += 1

        return ans