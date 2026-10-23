class Solution:
    def minCost(self, nums1: list[int], nums2: list[int]) -> int:
        
        n = len(nums1)

        freqs = defaultdict(lambda : [0,0])

        ans = 0

        for i in range(n):
            freqs[nums1[i]][0] += 1
            freqs[nums2[i]][1] += 1
    
        for num,freq in freqs.items():
            freq1, freq2 = freq

            if (freq1 + freq2) % 2:
                return -1

            ans += abs(freq1 - freq2)

        return ans // 4