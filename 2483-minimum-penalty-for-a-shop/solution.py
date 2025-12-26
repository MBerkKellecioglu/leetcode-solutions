class Solution:
    def bestClosingTime(self, customers: str) -> int:
        
        n = len(customers)

        l = [0] * (n + 1)
        r = [0] * (n + 1)

        ans, mini = 0, float("inf")

        l[n - 1] = 0 
        r[0] = 0

        for i in range(n - 1, -1, -1):
            l[i] = l[i + 1] + (customers[i] == 'Y')

        for i in range(1, n + 1):
            r[i] = r[i - 1] + (customers[i - 1] == 'N')
            
        for i in range(0, n + 1):
            if mini > l[i] + r[i]:
                mini = l[i] + r[i]
                ans = i

        return ans