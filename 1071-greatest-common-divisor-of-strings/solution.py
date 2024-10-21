class Solution:

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        
        if len(str2) > len(str1):
            str2, str1 = str1, str2

        sol = str2

        sz1 = int(len(str1))
        sz2 = int(len(str2))

        def helper(s):
            i = 0
            j = 0

            while i < sz1:
                if str1[i: i + szs] != sol: return False
                else:  i += szs

            while j < sz2:
                if str2[j : j + szs] != sol: return False
                else: j += szs

            return True

        while len(sol) > 0:
            szs = len(sol)

            if sz1 % szs == 0 and sz2 % szs == 0:
                if helper(sol): 
                    return sol
            
            sol = sol[:-1]
            
        return sol