class Solution:
    def minNumberOfSeconds(self, m: int, w: List[int]) -> int:
        
        used = {}

        ans = float("-inf")

        heap = []

        for i in range(len(w)):
            used[i] = 0
            heappush(heap, [w[i], i])
        
        for i in range(m):
            time, ind = heappop(heap)

            ans = max(time, ans)
            num = w[ind]
            use = used[ind]
            used[ind] += 1
            heappush(heap, [time + ((use + 2) * num), ind])

        return ans