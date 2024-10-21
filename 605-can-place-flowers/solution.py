class Solution:
    def canPlaceFlowers(self, bed: List[int], n: int) -> bool:

        sz = len(bed)
        
        for i in range(sz):

            if not bed[i]:

                if i - 1 > -1 and bed[i - 1]:
                    continue
                
                if i + 1 < sz and bed[i + 1]:
                    continue
                
                bed[i] = 1
                n -= 1
                     
        return n <= 0
                    

                
