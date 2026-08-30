class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        
        n = len(num)

        def dfs(prev,total, idx):
            nonlocal n
            if idx >= n:
                return True

            for i in range(idx + 1,n + 1):
                sub = num[idx:i]
                value = int(sub)

                if value > total:
                    return False
                elif value == total and sub == str(total):
                    return dfs(total, prev + total, i)

            return False

        for i in range(1,n - 1):
            sub1 = num[:i]
            val1 = int(sub1)

            if str(val1) != sub1:
                return False

            for j in range(i + 1, n):
                sub2 = num[i:j]
                val2 = int(sub2)

                if str(val2) != sub2:
                    break

                if dfs(val2,val1 + val2, j):
                    return True
        
        return False