class Solution:
    def calculate(self, s: str) -> int:
    
        stack = []

        res,num,sign = 0,0,1

        # There is always a better way...

        for c in s:
            if c.isdigit():
                num = num*10 + int(c)

            elif c == "+":
                res += sign * num
                num = 0
                sign = 1
            elif c == "-":
                res += sign * num
                num = 0
                sign = -1
            elif c == "(":
                stack.append(res)
                stack.append(sign)

                res = 0
                sign = 1
            elif c == ")":
                res += (num * sign)

                num = 0

                res *= stack.pop()

                res += stack.pop()

        res += sign * num

        return res 

                
