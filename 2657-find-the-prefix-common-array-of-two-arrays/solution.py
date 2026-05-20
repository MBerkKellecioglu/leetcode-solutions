class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        
        n, count = len(A), 0 

        freq = [0] * (51)

        C = []

        for i in range(n):
            freq[A[i]] += 1
            freq[B[i]] += 1
            
            if A[i] != B[i]:
                if freq[A[i]] >= 2:
                    count += 1
                if freq[B[i]] >= 2:
                    count += 1
            else:
                count += 1

            C.append(count)

        return C
            