class Solution:
    def smallestPalindrome(self, s: str) -> str:
        
        alpha = [0] * 26

        a = ord('a')

        ans = ""

        for c in s:
            alpha[ord(c) - a] += 1
        
        for i in range(26):
            if alpha[i] % 2:
                ans += chr(i + a)
                alpha[i] -= 1
        
        for i in range(25, -1, -1):
            if alpha[i]:
                mul = alpha[i] // 2
                ans = str(chr(i + a) * mul) + ans + str(chr(i + a) * mul)

        return ans

            