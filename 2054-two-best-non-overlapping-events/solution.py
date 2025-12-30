class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        
        n, ans = len(events), float("-inf")

        events.sort()

        highest = [0] * n

        highest[n - 1] = events[n - 1][2]

        for i in range(n - 2, -1, -1):
            highest[i] = max(highest[i + 1], events[i][2])

        
        for i in range(n):
            target, flag = events[i][1], False
            l, r = i + 1, n - 1

            while l <= r:
                mid = (l + r) // 2

                if events[mid][0] > target and events[mid - 1][0] <= target:
                    flag = True
                    break
                elif events[mid][0] <= target:
                    l = mid + 1
                else:
                    r = mid - 1
            
            if flag:
                ans = max(ans, highest[mid] + events[i][2])
            else:
                ans = max(ans, events[i][2])
        
        return ans