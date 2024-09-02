class Solution:
    def fractionAddition(self, expression: str) -> str:
        
        pattern = re.compile("(\+|\-)?[0-9]+/[0-9]+")

        fractions = [m.group() for m in re.finditer("(\+|\-)?[0-9]+/[0-9]+", expression)]

        if len(fractions) == 1:
            return self.reduce(fractions[0])

        sol = self.calculate(fractions[0], fractions[1])

        for i in range(2, len(fractions)):
            sol = self.calculate(sol, fractions[i])

        sol = self.reduce(sol)

        return sol

    def calculate(self, fraction1, fraction2):
        denomitor1 = int(fraction1[fraction1.find("/") + 1: len(fraction1)])
        denomitor2 = int(fraction2[fraction2.find("/") + 1: len(fraction2)])

        numerator1 = int(fraction1[0 : fraction1.find("/")])
        numerator2 = int(fraction2[0 : fraction2.find("/")])

        new_denomitor = self.LCM(denomitor1, denomitor2, 0)
        new_numerator = int(numerator1 * (new_denomitor / denomitor1) + numerator2 * (new_denomitor / denomitor2))

        return str(new_numerator) + "/" + str(new_denomitor)

    def LCM(self, num1, num2, reduce):
        
        n2 = abs(num2)
        n1 = abs(num1)

        if n2 > n1:
            n2, n1 = n1, n2
        
        while n1 % n2 > 0:
            tmp = n1 % n2
            n1 = n2
            n2 = tmp
        
        if reduce == 1:
            return n2

        return int(num1*num2 / n2)
    
    def reduce(self, fraction):
        denomitor = int(fraction[fraction.find("/") + 1: len(fraction)])
        numerator = int(fraction[0 : fraction.find("/")])

        if numerator == 0:
            return "0/1"

        gcd = self.LCM(denomitor, numerator, 1)

        if gcd != -1 and denomitor % gcd == 0 and numerator % gcd == 0:
            denomitor = int(denomitor / gcd)
            numerator = int(numerator / gcd)

        return str(numerator) + "/" + str(denomitor)
        
            