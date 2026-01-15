class Solution:
    def lastRemaining(self, n: int) -> int:
        
        dir = 0 # 0 means left 1 means right

        head, step = 1, 1

        while n > 1:
            if (not dir) or (dir and n % 2):
                head += step

            step *= 2
            n //= 2
            dir ^= 1

        return head
            