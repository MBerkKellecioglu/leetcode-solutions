class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        
        lower = set()
        upper = set()

        occur = defaultdict(lambda : [-1] * 2) # first is first Upper, second is last Lower

        for i in range(len(word)):
            c = word[i]
            if c.islower():
                lower.add(c)
                occur[c][1] = i
            else:
                upper.add(c.lower())

                if occur[c.lower()][0] == -1:
                    occur[c.lower()][0] = i 
                
        discount = 0

        for ind in occur.values():
            if ind[0] != -1 and ind[0] <= ind[1]:
                discount += 1


        return len(lower & upper) - discount
        
                