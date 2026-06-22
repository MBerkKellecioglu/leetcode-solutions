class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        
        baloons = defaultdict(int)

        ans = float("inf")

        for c in "balon":
            baloons[c] = 0

        for c in text:
            if c in "balon":
                baloons[c] += 1
        
        for c,f in baloons.items():
            if c in "lo":
                ans = min(ans, f // 2)
            else:
                ans = min(ans, f)

        return ans