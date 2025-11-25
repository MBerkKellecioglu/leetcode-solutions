class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        
        res = set()
        left = set()
        right = Counter(s)

        for middle in s:

            right[middle] -= 1

            for l in left:

                if right[l] > 0:
                    res.add((middle, l))

            left.add(middle)

        return len(res)