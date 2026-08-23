class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        
        if len(s1) < len(s2):
            s1,s2 = s2,s1

        arr1 = s1.split()
        arr2 = s2.split()

        n1, n2 = len(arr1), len(arr2)

        r1,r2 = n1 - 1, n2 - 1
        pre, suff = 0, 0

        while r2 > -1:
            if arr1[r1] == arr2[r2]:
                r2 -= 1
                r1 -= 1
                suff += 1
            else:
                break

        while pre < len(arr2):
            if arr1[pre] == arr2[pre]:
                pre += 1
            else:
                break

        
        return pre + suff >= len(arr2)