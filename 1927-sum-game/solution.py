class Solution:
    def sumGame(self, num: str) -> bool:
        
        n = len(num)

        l_sum, r_sum = 0,0

        lq, rq = 0,0 # question marks

        for i in range(n // 2):
            if num[i] != '?':
                l_sum += int(num[i])
            else:
                lq += 1
        
        for i in range(n//2,n):
            if num[i] != '?':
                r_sum += int(num[i])
            else:
                rq += 1

        if (lq + rq) % 2 == 0:
            if ((rq - lq) // 2) * 9 == l_sum - r_sum:
                return False

        return True
        
