class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        
        n, m = len(servers), len(tasks)

        available = []
        ans = []

        for i in range(n):
            available.append((servers[i], i)) # available servers ==> [weight of the server, server idx]
        
        heapify(available)

        time = 0
        task_idx = 0

        busy = [] # busy servers ==> holds [end time of current task, server idx]

        while task_idx < m:
            if time < task_idx: # task_idx always gets 1 more step than time from prev step of the loop
                time = task_idx

            if not available:
                time = max(time, busy[0][0]) # advance time till there is available server

            while busy and busy[0][0] <= time:
                server_idx = busy[0][1]
                heappop(busy)

                heappush(available, (servers[server_idx], server_idx))
          
            while task_idx <= time and task_idx < m and available:
                weight, server_idx = heappop(available)
                next_task = tasks[task_idx]
                task_idx += 1

                heappush(busy, (next_task + time, server_idx))
                ans.append(server_idx)

        return ans





