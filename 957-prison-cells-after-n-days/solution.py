class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:

        def change(prev):
            nxt = prev[:]

            nxt[0], nxt[-1] = 0, 0

            for cell in range(1,7):
                nxt[cell] = 1 if (prev[cell - 1] ^ prev[cell + 1] == 0) else 0

            return nxt
        
        first = change(cells)
        curr = first[:]

        pattern = [first]

        while 1:
            curr = change(curr)

            if curr == first:
                break
            
            pattern.append(curr)
        
        sz = len(pattern)

        return pattern[(n - 1) % sz]


