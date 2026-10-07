class Solution:
    def weightedSum(self, parent: list[int], nums: list[int]) -> int:

        n = len(parent)
        
        tree = defaultdict(list)

        h, ans = 1, 0

        depth = [0] * n

        for idx, p in enumerate(parent):
            tree[p].append(idx)

        q = deque()
        q.append(0)

        while q:
            sz = len(q)

            while sz > 0:

                curr = q.popleft()

                depth[curr] = h

                for nxt in tree[curr]:
                    q.append(nxt)
                
                sz -= 1
            
            h += 1
        
        h -= 1

        for idx, num in enumerate(nums):
            ans += num * (h - depth[idx] + 1)

        return ans
                


