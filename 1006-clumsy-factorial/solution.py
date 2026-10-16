class Solution:
    def clumsy(self, n: int) -> int:
        
        stack = []

        op = ["*","/","+","-"]

        op_idx, ans = 0, 0

        for num in range(n,0,-1):

            if stack and stack[-1] in "*/":
                curr_op = stack.pop()
                prev_num = stack.pop()

                if curr_op == "*":
                    stack.append(prev_num * num)
                else:
                    stack.append(prev_num // num)
            else:
                stack.append(num)

            if num != 1:
                stack.append(op[op_idx])

            op_idx = (op_idx + 1) % 4
        
        
        while stack:
            num = stack.pop()

            if stack:
                if stack[-1] == "-":
                    ans += (-1) * num
                else:
                    ans += num
                
                stack.pop()
            else:
                ans += num
        
        
        return ans

