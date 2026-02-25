class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        
        bits = defaultdict(list)
        ans = []

        def findSetBits(n):

            count = 0

            while n > 0:
                count += n % 2
                n //= 2

            return count

        for i in range(len(arr)):
            bits[findSetBits(arr[i])].append(arr[i])

        for key, val in sorted(bits.items()):
            bits[key].sort()
            ans.extend(bits[key])

        return ans
