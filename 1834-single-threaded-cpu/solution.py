class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        
        n, time = len(tasks), 0
    
        available = []
        ans = []

        sorted_tasks = []

        for idx, task in enumerate(tasks):
            sorted_tasks.append([task[0], task[1], idx])
        
        sorted_tasks.sort()

        time = 0
        tasks_idx = 0
        processing = None

        while tasks_idx < n or available:

            if not available and time < sorted_tasks[tasks_idx][0]:
                time = sorted_tasks[tasks_idx][0]
                
            while tasks_idx < n and time >= sorted_tasks[tasks_idx][0]:
                enq_time, pro_time, idx = sorted_tasks[tasks_idx]

                tasks_idx += 1

                heappush(available, (pro_time, idx))
            
            pro_time, idx = heappop(available)

            time += pro_time
            ans.append(idx)
           
        return ans