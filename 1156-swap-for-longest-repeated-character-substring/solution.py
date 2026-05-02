class Solution:
    def maxRepOpt1(self, text: str) -> int:
        
        freq = [-1 for i in range(26)]
        
        # Run Length Encoded
        RLE = []

        i, n, ans =  0, len(text), 1

        while i < n:
            c = text[i]
            count, ind = 0, ord(c) - ord('a')

            if freq[ind] == -1:
                freq[ind] = text.count(c)
            
            while i < n and text[i] == c:
                i += 1
                count += 1
            
            RLE.append((c, count))

        m = len(RLE)

        for j in range(m):
            c, f = RLE[j] # current character and frequency

            ind = ord(c) - ord('a') # just ASCII conversion

            ans = max(ans, f)

            if (j + 1 < m or j - 1 > -1) and freq[ind] > f:
                ans = max(ans, f + 1)
            
            if j + 2 < m and RLE[j + 2][0] == c and RLE[j + 1][1] == 1:
                c2, f2 = RLE[j + 2]
                add = 0

                if f + f2 < freq[ind]:
                    add = 1

                ans = max(ans, f + f2 + add)

        return ans