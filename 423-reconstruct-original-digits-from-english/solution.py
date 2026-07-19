class Solution:
    def originalDigits(self, s: str) -> str:
        
        alpha = defaultdict(int)

        count = [0] * 10

        ans = ""

        digits = [
            "zero","one","two","three","four",
            "five","six","seven","eight","nine"
        ]

        for c in s:
            alpha[c] += 1

        for i in range(0,10,2):
            digit = digits[i]

            if alpha[digit[0]] and alpha[digit[1]] and alpha[digit[2]]:
                freq = min(alpha[digit[0]],alpha[digit[1]],alpha[digit[2]])
                count[i] += freq
                for c in digit:
                    alpha[c] -= freq
        
        for i in range(1,8,2):
            digit = digits[i]

            if alpha[digit[0]]:
                freq = alpha[digit[0]]
                count[i] += freq
                for c in digit:
                    alpha[c] -= freq
        
        count[9] = alpha['n'] // 2

        for i in range(10):
            ans += str(i) * count[i]

        return ans

             

        return ""
