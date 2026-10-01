class Solution:
    def sortEvenOdd(self, nums: list[int]) -> list[int]:
        
        n = len(nums)

        even = [nums[i] for i in range(0,n,2)]
        odd = [nums[i] for i in range(1,n,2)]

        even.sort()
        odd.sort(reverse=True)

        ans = []

        for i in range(n):
            if not i % 2:
                ans.append(even[i // 2])
            else:
                ans.append(odd[i // 2])

        return ans

