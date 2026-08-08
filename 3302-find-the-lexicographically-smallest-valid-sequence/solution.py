class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        
        n1,n2 = len(word1), len(word2)
        w2 = n2 - 1

        suffix = [n2] * (n1 + 1)
        ans = []

        for w1 in range(n1 - 1,-1,-1):
            if w2 >= 0 and word1[w1] == word2[w2]:
                w2 -= 1

            suffix[w1] = w2 + 1
        
        w2, changed = 0, False

        for w1 in range(n1):
            if w2 == n2:
                break

            if word1[w1] == word2[w2]:
                w2 += 1
                ans.append(w1)
            elif not changed and suffix[w1 + 1] <= w2 + 1:
                w2 += 1
                ans.append(w1)
                changed = True
        
        if len(ans) != n2:
            return []

        return ans    

    



                


                


