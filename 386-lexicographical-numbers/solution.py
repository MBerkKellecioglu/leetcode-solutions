class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        
        ans = []

        num = 1

        for _ in range(n):
            ans.append(num)

            if num * 10 <= n:
                num *= 10
            else:
                while num >= n or num % 10 == 9:
                    num //= 10
            
                num += 1

        return ans