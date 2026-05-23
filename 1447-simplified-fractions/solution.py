class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        
        ans = []

        def gcd(a, b):

            while b != 0:
                a, b = b, a % b

            return a

        for d in range(2, n + 1):
            for n in range(1, d):

                if gcd(d, n) == 1:
                    ans.append(str(n) + "/" + str(d))
            
        return ans
