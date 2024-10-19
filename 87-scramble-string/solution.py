class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:

        dp = {}

        def dfs(cs1, cs2):
            if len(cs1) == 1 and cs1 == cs2:
                return True

            if cs1 == cs2:
                return True

            if (cs1, cs2) in dp:
                return dp[(cs1,cs2)]
            
            n = len(cs1)

            for i in range(1, n):
                
                if dfs(cs1[0:i],cs2[0:i]) and dfs(cs1[i:], cs2[i:]): #dont swap
                    dp[(cs1, cs2)] = True
                    return True
                
                if dfs(cs1[0:i], cs2[n - i:]) and dfs(cs1[i:], cs2[0:n - i]): #swap
                    dp[(cs1, cs2)] = True
                    return True
            
            dp[(cs1, cs2)] = False

            return False 
        
        return dfs(s1, s2)



        