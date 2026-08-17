class Solution:
    def smallestNumber(self, num: int) -> int:

        if num == 0:
            return 0
        
        digits, negative, flag = [0] * 10, num < 0, True

        ans = ""

        num = abs(num)

        while num > 0:
            digits[num % 10] += 1
            num //= 10

        if not negative:
            for i in range(1, 10):
                if digits[i] != 0 and flag:
                    ans += str(i) + ("0" * digits[0]) + (str(i) * (digits[i] - 1))
                    flag = False
                else:
                    ans += str(i) * digits[i]
        else:
            for i in range(9, -1, -1):
                ans += str(i) * digits[i]

        return int(ans) * -1 if negative else int(ans)