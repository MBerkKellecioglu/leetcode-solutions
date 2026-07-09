class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        
        """Apparently there was a better and more clever solution where we segment 
           the array. We are doing that considering we cant reach any node from
           nums[i] to nums[i + 1...n] (i from i + 1 to n) if nums[i + 1] - nums[i] > maxDiff"""

        segments = [0] * n
        segment_index = 0

        ans = []

        for i in range(n - 1):
            segments[i] = segment_index

            if nums[i + 1] - nums[i] > maxDiff:
                segment_index += 1
        
        segments[-1] = segment_index
        
        for ui, vi in queries:
            ans.append(segments[ui] == segments[vi])
        
        return ans

