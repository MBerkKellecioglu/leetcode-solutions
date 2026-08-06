class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        
        num = n

        while 1:
            s = str(num)
            mul = 1

            for d in s:
                mul *= int(d)

                if mul % t == 0:
                    return num
            
            num += 1