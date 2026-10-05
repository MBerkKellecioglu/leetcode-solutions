class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        
        num = n + 1

        while 1:
            freq = Counter(str(num))

            valid = True

            for digit,f in freq.items():
                if int(digit) != f:
                    num += 1

                    valid = False
                    break
                    
            if valid:
                return num
        
        return -1