class Solution:
    def threeConsecutiveOdds(self, arr: list[int]) -> bool:

        seq = 0
        
        for num in arr:
            if num % 2:
                seq += 1
            else:
                seq = 0

            if seq == 3:
                return True
            
        return False