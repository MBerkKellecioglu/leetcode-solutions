class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        
        sorted_arr = sorted(set(arr))
        ans = []

        ranks = defaultdict(lambda : -1)

        for rank, num in enumerate(sorted_arr, 1):
            ranks[num] = rank

        for num in arr:
            ans.append(ranks[num])
        
        return ans
        