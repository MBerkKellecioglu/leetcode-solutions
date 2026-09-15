class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        
        prev = [1]
        
        for i in range(1,rowIndex + 1):
            sz = len(prev) 
            nxt = [1]
            
            for j in range(1,sz):
                nxt.append(prev[j] + prev[j - 1])
            nxt.append(1)
            prev = nxt[:]
        
        return prev
                
            
        