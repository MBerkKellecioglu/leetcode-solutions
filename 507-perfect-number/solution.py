class Solution:
    def checkPerfectNumber(self, num: int) -> bool:

        if num == 1:
            return False

        total = 1

        for div in range(2, int(sqrt(num)) + 1):
            if num % div == 0:
                total += div

                if div * div != num:
                    total += (num // div)

        return (total == num)

        