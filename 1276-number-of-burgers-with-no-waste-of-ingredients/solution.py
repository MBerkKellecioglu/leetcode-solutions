class Solution:
    def numOfBurgers(self, tomato: int, cheese: int) -> List[int]:
        
        jumbo = (tomato - (2*cheese))

        if jumbo % 2 != 0 or jumbo < 0 or cheese - (jumbo // 2) < 0:
            return []
        
        return [jumbo // 2, cheese - (jumbo // 2)]