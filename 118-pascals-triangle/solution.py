class Solution:
    def generate(self, rows: int) -> List[List[int]]:
        
        ans = [[1]]

        for i in range(rows - 1):
            nxt = [1] 
            for j in range(len(ans[-1]) - 1):
                nxt.append(ans[-1][j] + ans[-1][j + 1])
            
            nxt.append(1)

            ans.append(nxt)
        
        return ans

             