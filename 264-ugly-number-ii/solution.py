class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
        minheap = []
        dp = [0] * n
        checked = defaultdict(bool)

        dp[0] = 1

        heappush(minheap, 2)
        heappush(minheap, 3)
        heappush(minheap, 5)

        for i in range(1,n):
            curr = minheap[0]
            dp[i] = curr

            heappop(minheap)
            if not checked[curr*2]:
                heappush(minheap, curr*2)
                checked[curr*2] = True
            if not checked[curr*3]:
                heappush(minheap, curr*3)
                checked[curr*3] = True
            if not checked[curr*5]:
                heappush(minheap, curr*5)
                checked[curr*5] = True

        return dp[n - 1]