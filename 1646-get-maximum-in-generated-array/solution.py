class Solution:
    def getMaximumGenerated(self, n: int) -> int:

        if n == 0:
            return 0

        arr = [0] * (n + 1)

        arr[1] = 1

        ans = arr[n]

        for i in range(2, n + 1):
            if not i % 2:
                arr[i] = arr[i // 2]
            else:
                arr[i] = arr[i // 2] + arr[(i // 2) + 1]
            
            ans = max(ans,arr[i])
        
        return ans