class Solution:
    def minCost(self, n: int) -> int:
         
        # x = a + b  a -> 1,2,... n// 2 
        # 5 -> 1,4 -> 4
        # 4 -> 1,3 -> 3
        # 3 -> 1,2 -> 2
        # 2 -> 1,1 -> 1

        # to minimize a * b select minimize a and maximize b that means a = 1, b = x - 1

        return ((n) * (n - 1)) // 2
