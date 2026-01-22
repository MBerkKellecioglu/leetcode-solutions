class Solution:
    def getHint(self, s: str, g: str) -> str:
        
        n, bulls, cows = len(s), 0, 0
        
        freq1 = defaultdict(int)
        freq2 = defaultdict(int)

        for i in range(n):
            if s[i] == g[i]:
                bulls += 1
            else:
                freq1[s[i]] += 1
                freq2[g[i]] += 1

        for i in range(n):
            if (freq1[s[i]] > 0 and freq2[s[i]] > 0):
                cows += 1
                freq1[s[i]] -= 1
                freq2[s[i]] -= 1

        return str(bulls) + "A" + str(cows) + "B"