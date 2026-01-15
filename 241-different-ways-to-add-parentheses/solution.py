class Solution:
    def diffWaysToCompute(self, exp: str) -> List[int]:
        
        ops = {'+': operator.add, '-': operator.sub, '*': operator.mul}

        def helper(exp,l, r):
            if exp[l : r + 1].isnumeric():
                return [int(exp[l:r + 1])]

            ans = []

            for i in range(l, r + 1):

                if not exp[i].isnumeric():
                    op = exp[i]
                    h1 = helper(exp, l, i - 1)
                    h2 = helper(exp, i + 1, r)
                    
                    for j in range(len(h1)):
                        for k in range(len(h2)):
                            ans.append(ops[op](int(h1[j]),int(h2[k])))  

            return ans
                
        return helper(exp, 0, len(exp) - 1)    