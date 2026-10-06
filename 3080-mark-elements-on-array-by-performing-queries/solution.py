class Solution:
    def unmarkedSumArray(self, nums: List[int], queries: List[List[int]]) -> List[int]:

        n, total = len(nums), sum(nums)
        
        heap = [(val,idx) for idx,val in enumerate(nums)]

        heapify(heap)

        marked = [0] * n
        ans = []

        for q_index,k in queries:
            if not marked[q_index]:
                total -= nums[q_index]
                marked[q_index] = 1

            while heap and k > 0:
                val,idx = heappop(heap)

                if not marked[idx]:
                    k -= 1
                    marked[idx] = 1
                    total -= nums[idx]
            
            ans.append(total)
        
        return ans

