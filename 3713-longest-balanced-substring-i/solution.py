class Solution:
    def longestBalanced(self, s: str) -> int:
        
        n, ans = len(s), 1

        for i in range(n):
            freq = defaultdict(int)
            balance = 1

            for j in range(i, n):
                freq[ord(s[j]) - ord('a')] += 1
                
                balance = max(balance, freq[ord(s[j]) - ord('a')])

                if j - i + 1 == len(freq) * balance:
                    ans = max(ans, j - i + 1)

        return ans