class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:

        bank.insert(0,startGene)

        graph = defaultdict(list)

        n, ans = len(bank), 0

        checked = [0] * n

        for i in range(len(bank) - 1):
            for j in range(i + 1, len(bank)):
                diff = sum(c1 != c2 for c1, c2 in zip(bank[i],bank[j]))

                if diff == 1:
                    graph[i].append(j)
                    graph[j].append(i)
            
        q = deque()

        q.append(0)
        
        checked[0] = True

        while q:
            sz = len(q)

            while sz > 0:
                curr_idx = q.popleft()
                currGene = bank[curr_idx]

                if currGene == endGene:
                    return ans

                for next_idx in graph[curr_idx]:
                    if not checked[next_idx]:
                        q.append(next_idx)
                        checked[next_idx] = True
                
                sz -= 1

            ans += 1

        return -1
