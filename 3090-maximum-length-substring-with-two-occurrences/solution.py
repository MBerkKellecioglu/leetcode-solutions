class Solution:
    def maximumLengthSubstring(self, s: str) -> int: 
        ans, l = 0, 0

        freq = defaultdict(int)

        for r in range(len(s)):
            c = s[r]
            freq[c] += 1

            if freq[c] > 2:
                while freq[c] > 2:
                    freq[s[l]] -= 1
                    l += 1
            
            ans = max(ans, r - l + 1)

        return ans
