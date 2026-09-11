class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        
        freq = Counter(digits)

        ans = 0

        for num in range(100, 1000, 2):
            s = str(num)

            d1,d2,d3 = int(s[0]),int(s[1]),int(s[2])

            mini_freq = Counter([d1,d2,d3])
            
            valid = True

            for d,f in mini_freq.items():
                valid &= (freq[d] >= f)
            
            ans += int(valid)
        
        return ans


