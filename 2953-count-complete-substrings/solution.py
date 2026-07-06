class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        
        parts = []

        start, sz, ans = 0, len(word), 0

        for i in range(sz):
            if i + 1 < sz and abs(ord(word[i]) - ord(word[i + 1])) > 2:
                parts.append(word[start: i + 1])
                start = i + 1

        parts.append(word[start : sz])

        def helper(part, wsz, k):

            freq = defaultdict(int)
            valid = 0

            for i in range(wsz):
                freq[part[i]] += 1

            if max(freq.values()) == min(freq.values()) == k:
                valid += 1
            
            for i in range(wsz, len(part)):
                added = part[i]
                deleted = part[i - wsz]

                freq[added] += 1
                freq[deleted] -= 1

                if freq[deleted] == 0:
                    freq.pop(deleted)
                
                if max(freq.values()) == min(freq.values()) == k:
                    valid += 1
            
            return valid

        for part in parts:
            for i in range(1, 27):
                wsz = i * k # window size

                if wsz > len(part):
                    break
                
                ans += helper(part, wsz, k)
        
        return ans
