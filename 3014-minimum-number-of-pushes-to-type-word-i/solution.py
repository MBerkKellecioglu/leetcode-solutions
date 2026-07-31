class Solution:
    def minimumPushes(self, word: str) -> int:
        
        alpha = [0] * 26
        a = ord('a') 

        push, count, ans = 0, 0, 0

        freq = []

        for c in word:
            alpha[ord(c) - a] += 1
        
        for i in range(26):
            if alpha[i]:
                heappush(freq, -alpha[i])
        
        while freq:
            count += 1

            if count % 8 == 1:
                push += 1

            ans += -heappop(freq) * push
        
        return ans