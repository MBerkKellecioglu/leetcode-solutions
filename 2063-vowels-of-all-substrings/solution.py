class Solution:
    def countVowels(self, word: str) -> int:
        
        ans, n = 0, len(word)

        for i in range(n):
            if word[i] in "aeiou":
                l_size, r_size = i, n - i - 1
                ans += l_size + r_size + (l_size * r_size) + 1
        
        return ans

