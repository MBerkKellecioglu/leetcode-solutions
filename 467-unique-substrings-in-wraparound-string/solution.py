class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:

        length, ans = 1, 0

        max_len = defaultdict(int)

        max_len[s[0]] = 1

        for i in range(1, len(s)):
            if (ord(s[i]) - ord(s[i - 1])) % 26 == 1:
                length += 1
            else:
                length = 1

            max_len[s[i]] = max(max_len[s[i]], length)

        for c, length in max_len.items():
            ans += length
        
        return ans
        