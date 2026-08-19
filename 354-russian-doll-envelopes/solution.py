class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:

        n, ans = len(envelopes), 1
        
        """After sorting increasingly for first value and for equal first values sorting it decreasingly 
           question becomes LIS(300)"""
        envelopes.sort(key = lambda x: (x[0], -x[1]))

        lis = [envelopes[0][1]]

        for idx in range(1,n):
            _,h = envelopes[idx]

            lb = bisect_left(lis, h)

            if lb >= len(lis):
                lis.append(h)
            else:
                lis[lb] = h
            
            ans = max(ans, len(lis))
        
        return ans
