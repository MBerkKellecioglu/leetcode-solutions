class Solution:
    def maxProduct(self, words: list[str]) -> int:
        
        n, ans = len(words), 0

        masks = [0] * n

        for idx,word in enumerate(words):
            mask = masks[idx]
            for c in word:
                val = ord(c) - ord('a')

                mask |= (1 << val)
            
            masks[idx] = mask
        
        
        for i in range(n):
            word1 = words[i]
            mask1 = masks[i]
            for j in range(i + 1,n):
                word2 = words[j]
                mask2 = masks[j]

                if len(word1) * len(word2) > ans and not(mask1 & mask2):
                    ans = len(word1) * len(word2)

        return ans
