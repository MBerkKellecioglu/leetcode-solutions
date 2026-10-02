class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        
        max_depth, b = 0,0

        n = len(seq)

        for c in seq:
            if c == '(':
                b += 1
            else:
                b -= 1
            
            max_depth = max(max_depth,b)
        
        # if under treshold 0 else 1 
        treshold = max_depth // 2

        ans = [0] * n

        # reset open brackets
        b = 0

        for idx,c in enumerate(seq):
            #if current depth is higher than treshold it belongs to 1 group
            if c == '(':
                b += 1
            
            ans[idx] = int(b > treshold)

            # the reason for decrementing after we assing group is that to match closing brackets with valid group
            if c == ')':
                b -= 1

        return ans 




