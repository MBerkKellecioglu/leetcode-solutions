class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        
        n = len(letters) - 1

        l, r, ans = 0, n, n

        while l <= r:
            mid = (l + r) // 2

            if target >= letters[mid]:
                l = mid + 1
            else:
                ans = min(ans, mid)
                r = mid - 1

        if ans == n and letters[ans] <= target:
            return letters[0]
        
        return letters[ans]