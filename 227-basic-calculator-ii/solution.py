class Solution:
    def calculate(self, s: str) -> int:
        
        # I suck at coding LOL

        stack = []

        num = 0
        op = "+"

        for i,c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)

            if c in "+-/*" or i == len(s) - 1:
                if op == "+":
                    stack.append(num)
                elif op == "-":
                    stack.append(-num)
                elif op == "*":
                    stack.append(stack.pop() * num)
                elif op == "/":
                    stack.append(int(stack.pop() / num))
                
                num = 0
                op = c
    
        return sum(stack)