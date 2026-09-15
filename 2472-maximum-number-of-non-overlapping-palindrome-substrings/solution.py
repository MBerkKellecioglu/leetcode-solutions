class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        
        n = len(s)

        idx = 0

        ans = 0

        def palindrome(sub):
            if sub == "":
                return False

            l,r = 0, len(sub) - 1

            while l <= r:
                if sub[l] != sub[r]:
                    return False
                l += 1
                r -= 1

            return True

        while idx <= n - k:
            l, r = idx, idx + k

            sub1 = s[l:r]
            sub2 = ""

            if r + 1 <= n:
                sub2 = s[l:r + 1]

            if palindrome(sub1):
                idx += k
                ans += 1
                continue
            
            if palindrome(sub2):
                idx += k + 1
                ans += 1
                continue
 
            idx += 1
        
        return ans
