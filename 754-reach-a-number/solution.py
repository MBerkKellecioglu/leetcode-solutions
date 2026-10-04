class Solution:
    def reachNumber(self, target: int) -> int:
        
        move = 1

        target = abs(target)

        while 1:
            total = ((move) * (move + 1)) // 2

            if total >= target and (total - target) % 2 == 0:
                return move

            move += 1
        
        return -1