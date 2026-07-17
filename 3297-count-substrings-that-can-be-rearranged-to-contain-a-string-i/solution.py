class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        
        n, m = len(word1), len(word2)

        anchor = ord('a')

        ans, valid = 0, 0

        pattern = [0] * 26
        sub = [0] * 26

        l, r = 0, 0

        for c in word2:
            pattern[ord(c) - anchor] += 1

        while r < n:
            cr = ord(word1[r]) - anchor
            sub[cr] += 1

            if pattern[cr] > 0 and sub[cr] <= pattern[cr]:
                valid += 1

            while valid == m:
                cl = ord(word1[l]) - anchor
                
                ans += n - r
                sub[cl] -= 1
                l += 1

                if pattern[cl] > sub[cl]:
                    valid -= pattern[cl] - sub[cl]

            r += 1
        
        return ans
            



        
