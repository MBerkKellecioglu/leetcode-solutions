class Solution:
    dp = {}
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0

        if num2 < 100:
            return 0
    
        for i in range(max(num1, 100), num2 + 1):
            num = str(i)
            ind = 0
            wave = 0

            while ind + 2 < len(num):
                split = num[ind: ind + 3]

                if int(split) in self.dp:
                    wave += self.dp[int(split)] 
                elif (split[0] < split[1] and split[1] > split[2]) or (split[0] > split[1] and split[1] < split[2]):
                    wave += 1
                    self.dp[int(split)] = 1
                
                ind += 1
             
            self.dp[num] = wave
            ans += wave

        return ans
