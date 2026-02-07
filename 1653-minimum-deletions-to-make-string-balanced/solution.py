class Solution:
    def minimumDeletions(self, s: str) -> int:
        
        n = len(s)

        delete, b = 0, 0

        for i in range(n):
            if s[i] == 'b':
                b += 1
            else:
                delete = min(delete + 1, b)

        return delete