class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        
        l, r, c = 0, 0, 0

        for m in moves:
            if m == "L":
                l += 1
            elif m == 'R':
                r += 1
            else:
                c += 1
        
        return max(l, r) - min(l,r) + c