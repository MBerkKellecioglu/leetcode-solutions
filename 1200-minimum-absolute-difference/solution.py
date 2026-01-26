class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        
        n, diff = len(arr), float("inf")

        arr.sort()

        ans = []

        for i in range(1, n):        
            diff = min(diff, arr[i] - arr[i - 1])

        for i in range(1, n):
            if arr[i] - arr[i - 1] == diff:
                ans.append([arr[i - 1], arr[i]])

        return ans    