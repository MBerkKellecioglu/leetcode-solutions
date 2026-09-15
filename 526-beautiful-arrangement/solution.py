class Solution:
    def countArrangement(self, n: int) -> int:
        
        dp  = {}
        
        def dfs(idx,mask):
            if mask == (1<<n) - 1:
                return 1
            
            if (idx,mask) in dp:
                return dp[(idx,mask)]
            
            valid = 0
            
            for num in range(n):
                b = (idx % (num + 1)) == 0 or ((num + 1) % idx) == 0
                
                if b and not(mask & (1 << num)):
                    valid += dfs(idx + 1, mask | (1 << num))
            
            dp[(idx,mask)] = valid
            
            return valid
        
        return dfs(1,0)
        
            
            
            
        