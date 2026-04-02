class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        
        even = defaultdict(int)
        odd = defaultdict(int)


        for i in range(len(s1)):
            if i % 2:
                even[s1[i]] += 1
                even[s2[i]] -= 1
            else:
                odd[s1[i]] += 1
                odd[s2[i]] -= 1

        for k, v in even.items():
            if v != 0:
                return False
        
        for k, v in odd.items():
            if v != 0:
                return False

        return True
        

