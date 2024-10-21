class Solution:
    def reverseWords(self, s: str) -> str:
        
        word = ""
        sol = ""

        words = []

        for c in s:
            if c.isalpha() or c.isnumeric():
                word += c
            else:
                if word != "":
                    words.append(word)

                word = ""
        
        if word != "":
            words.append(word)

        for i in range(len(words) - 1, -1, -1):
            sol += words[i] + " "

        return sol[:-1]

