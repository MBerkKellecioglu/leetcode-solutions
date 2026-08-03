class Solution:
    def knightDialer(self, n: int) -> int:
        
        jump = {
            0: [4,6],
            1: [6,8],
            2: [7,9],
            3: [4,8],
            4: [0,3,9],
            6: [0,1,7],
            7: [2,6],
            8: [1,3],
            9: [2,4]
        }

        prev = [1] * 10
        MOD = 10**9 + 7

        for _ in range(1,n):
            nxt = [0] * 10
            for num, nxt_nums in jump.items():
                for nxt_num in nxt_nums:
                    nxt[num] = (nxt[num] + prev[nxt_num]) % MOD
            
            prev = nxt[:]
        
        return sum(prev) % MOD