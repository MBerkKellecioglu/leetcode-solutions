class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        
        n, ans = len(words), float("inf")

        targetIndexes = []

        for i in range(n):
            if target == words[i]:
                targetIndexes.append(i)
        
        if not len(targetIndexes):
            return -1
        
        for idx in targetIndexes:
            diff = abs(startIndex - idx)

            ans = min(ans, min(diff, (n - diff)))
        
        return ans