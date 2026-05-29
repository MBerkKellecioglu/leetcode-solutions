class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:

        ans = 0

        if k == 0:
            freq = Counter(nums)

            for num in freq:
                if freq[num] >= 2:
                    ans += 1

            return ans
        
        unique = set(nums)


        for num in unique:
            if num + k in unique:
                ans += 1

        return ans