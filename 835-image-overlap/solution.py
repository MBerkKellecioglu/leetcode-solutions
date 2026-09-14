class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        
        n = len(img1)
        
        ones1 = []
        ones2 = []
        
        for i in range(n):
            for j in range(n):
                if img1[i][j]:
                    ones1.append((i,j))
                if img2[i][j]:
                    ones2.append((i,j))
        
        diff = defaultdict(int)
        
        ans = 0
        
        for y1,x1 in ones1:
            for y2,x2 in ones2:
                vec = (x1-x2,y1-y2)
                diff[vec] += 1
                
                ans = max(ans,diff[vec])
        
        return ans
        
        