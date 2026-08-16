class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        
        freq = [0] * 3

        for stone in stones:
            freq[stone % 3] += 1

        if freq[0] % 2 == 0:
            if freq[1] > 0 and freq[2] > 0:
                return True
            else:
                return False
        else:
            if abs(freq[1] - freq[2]) > 2:
                return True
            else:
                return False
        
