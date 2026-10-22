class Solution:
    def kSmallestPairs(self, nums1: list[int], nums2: list[int], k: int) -> list[list[int]]:

        m,n = len(nums1),len(nums2)
        
        heap = []

        ans = []

        for idx,num in enumerate(nums1):
            pair_vals = (num + nums2[0] ,idx, 0)

            heappush(heap, pair_vals)

        for i in range(k):
            _,idx1,idx2 = heappop(heap)

            ans.append((nums1[idx1],nums2[idx2]))

            if idx2 + 1 < n:
                pair_vals = (nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1)
                heappush(heap,pair_vals)
        
        return ans