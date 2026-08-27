class Solution:
    def canMakeSubsequence(self, s: str, t: str) -> bool:
        
        m, n = len(s), len(t)

        prefix = [float("inf")] * (m + 1)
        prefix[0] = -1

        suffix = [float("-inf")] * (m + 1)
        suffix[m] = n

        t_idx = 0

        for i in range(1, m + 1):
            while t_idx < n and t[t_idx] != s[i - 1]:
                t_idx += 1

            if t_idx < n:
                prefix[i] = t_idx
                t_idx += 1
            else:
                break

        t_idx = n - 1

        for i in range(m - 1, -1, -1):
            while t_idx >= 0 and t[t_idx] != s[i]:
                t_idx -= 1

            if t_idx >= 0:
                suffix[i] = t_idx
                t_idx -= 1
            else:
                break
        
        for i in range(m):
            if prefix[i] != float("inf") and suffix[i + 1] != float("-inf"):
                if suffix[i + 1] - prefix[i] >= 2:
                    return True

        return False

        

        