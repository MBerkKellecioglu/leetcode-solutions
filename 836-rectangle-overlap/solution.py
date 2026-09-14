class Solution:
    def isRectangleOverlap(self, a: List[int], b: List[int]) -> bool:
      
        
        x = max(a[0],b[0]) < min(a[2],b[2])
        
        y = max(a[1],b[1]) < min(a[3],b[3])
        
        return x and y