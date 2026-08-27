class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        
        n = len(target)
        
        freq = Counter(s)
        order = sorted(freq.keys())

        ans = ""

        candidate = (-1,-1) # idx, char

        for i in range(n):
            t = target[i]

            for c in order:
                if c > t and freq[c] > 0:
                    candidate = (i,c)
                    break

            if freq[t] > 0:
                freq[t] -= 1
            else:
                break

        if candidate == (-1,-1):
            return ""

        
        freq = Counter(s)

        for i in range(candidate[0]):
            freq[target[i]] -= 1
            ans += target[i]
        
        ans += candidate[1]
        freq[candidate[1]] -= 1

        for c in order:
            if freq[c] > 0:
                ans += (freq[c] * c)
                freq[c] = 0

        return ans
        