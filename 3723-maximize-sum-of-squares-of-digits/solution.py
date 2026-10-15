class Solution:
    def maxSumOfSquares(self, num: int, total: int) -> str:
        
        ans = ""

        while num > 0 and total > 0:
            digit = min(total,9)

            div = total // digit

            total %= digit

            ans += str(digit) * div

            if div > num:
                return ""
            
            num -= div
        
        if total > 0:
            return ""
        
        ans += num * "0"

        return ans