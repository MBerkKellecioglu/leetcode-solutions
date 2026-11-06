class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:

        # Pretty uncessary indexing problem. Not worth wasting your time on
        # Can solve indexing with python tricks probably but im lazy
        
        m = len(logs)

        freq = [0] * (n + 1)

        indexes = {}

        logs.sort(key=lambda x : x[1])

        for idx,q in enumerate(queries):
            indexes[idx] = q

        queries.sort()

        l,r,unique = 0,0,0

        requests = {}

        ans = []

        for end in queries:
            start = end - x

            while r < m and logs[r][1] <= end:
        
                if freq[logs[r][0]] == 0:
                    unique += 1

                freq[logs[r][0]] += 1

                r += 1
            
            while l < m and logs[l][1] < start:
                freq[logs[l][0]] -= 1

                if freq[logs[l][0]] == 0:
                    unique -= 1
            
                l += 1
       
            requests[end] = n - unique
        
        for idx in range(len(queries)):
            ans.append(requests[indexes[idx]])

        return ans
