class Solution:
    def minInsertions(self, s: str) -> int:
        
        balance = 0

        ans, n = 0, len(s)

        idx = 0

        while idx < n:
            c = s[idx]

            if c == '(':
                if balance % 2:
                    ans += 1
                    balance -= 1

                balance += 2
            else:
                if balance > 0:
                    balance -= 1
                else:
                    right = 0
                    while idx < n and s[idx] == ')':
                        right += 1
                        idx += 1
                    
                    if right % 2:
                        ans += (right + 3) // 2
                    else:
                        ans += right // 2
                
                    continue
                    
            idx += 1
        
        return ans + balance
