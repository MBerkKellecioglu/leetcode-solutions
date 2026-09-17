class Solution:
    def minDistance(self, word1: str, word2: str) -> int:

        # LCS problem but first submit was a mistake
        # I thought i was at LCS page LOL
        
        m,n = len(word1), len(word2)

        prev = [0] * (n + 1)

        for i in range(1, m + 1):
            nxt = [0] * (n + 1)
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    nxt[j] = prev[j - 1] + 1
                else:
                    nxt[j] = max(prev[j], nxt[j - 1])
            
            prev = nxt[:]

        return m + n - (2 * prev[n])