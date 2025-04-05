class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:

        ans = [0] * len(code)
        reverse = 0

        if k == 0:
            return ans
        
        if k < 0:
            code.reverse()
            reverse = 1
            k *= (-1)
        
        code *= 2
        sum = 0

        for i in range(1, k + 1):
            sum += code[i]

        for i in range(len(code) // 2):
            ans[i] = sum

            sum -= code[i + 1]
            sum += code[i + k + 1]

        if reverse:
            ans.reverse()

        return ans