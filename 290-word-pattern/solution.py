class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        
        p_word = {}
        word_p = {}
        
        words = s.split(" ")
        
        if len(pattern) != len(words):
            return False
        
        n = len(words)
        
        for i in range(n):
            p = pattern[i]
            word = words[i]
            
            if p in p_word:
                if p_word[p] != word:
                    return False
            else:
                p_word[p] = word
            
            if word in word_p:
                if word_p[word] != p:
                    return False
            else:
                word_p[word] = p
                
            
        
        return True
            