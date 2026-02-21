class Solution:
    def canCross(self, stones: List[int]) -> bool:
        
        n = len(stones)

        dp = defaultdict(bool)
        
        dp[(1, stones[0])] = True
       
        for i in range(1, n):
            for j in range(i - 1, -1, -1):
                diff = stones[i] - stones[j]

                if diff > stones[j] + 1:
                    break
                
                if dp[(diff, stones[j])]:
                    if i == n - 1:
                        return True
                    dp[(diff - 1, stones[i])] = True
                    dp[(diff, stones[i])] = True
                    dp[(diff + 1, stones[i])] = True
        
        return False
                
