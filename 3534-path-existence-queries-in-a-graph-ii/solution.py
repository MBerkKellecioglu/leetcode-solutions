class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        
        # This question was WAAAAY harder than i thought, apparently we need to use Binary Jumping

        ordered = sorted(nums)

        # 18 jumps is enough for maximum Diff because 2^17 > 10^5
        LOG = 18
        up = [[0 for _ in range(LOG)] for _ in range(n)]
        ans = []

        for i in range(n):
            ind = bisect_right(ordered, ordered[i] + maxDiff) - 1 
            up[i][0] = ind

        for k in range(1,LOG):
            for i in range(n):
                up[i][k] = up[up[i][k - 1]][k - 1]
        
        for ui, vi in queries:
            if ui == vi:
                ans.append(0)
                continue
            
            v1, v2 = min(nums[ui], nums[vi]), max(nums[ui], nums[vi])
                
            if v1 == v2:
                ans.append(1)
                continue

            curr_ind = bisect_right(ordered, v1) - 1
            max_ind = up[curr_ind][17] # 2^17 > 10^5 so we are checking if we can reach v2 

            if ordered[max_ind] < v2:
                ans.append(-1)
                continue

            steps = 0
            for k in range(LOG - 1, -1, -1):
                next_ind = up[curr_ind][k]

                if ordered[next_ind] < v2:
                    steps += (2**k)
                    curr_ind = next_ind

            ans.append(steps + 1)
        
        return ans



