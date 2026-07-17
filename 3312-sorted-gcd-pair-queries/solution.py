class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        
        # gcd pair results of nums at maximum can be maximum number of nums
        maxi = max(nums)

        count = [0] * (maxi + 1)
        
        tmp_pair = [0] * (maxi + 1)
        pair = [0] * (maxi + 1)  

        for num in nums:
            count[num] += 1
        
        for d in range(1, maxi + 1):
            # total number of d multiples (d,2d,3d...)
            total = 0
            for mul in range(d, maxi + 1, d):
                total += count[mul]

            tmp_pair[d] = (total * (total - 1)) // 2

        for d in range(maxi, 0, -1):
            # total number of false pairs for number d
            total = 0
            for mul in range(2*d, maxi + 1, d):
                total += pair[mul]
            
            pair[d] = tmp_pair[d] - total

        # Now that we have every gcd pair result and their frequency we can calculate which query
        # corresponds to which result 
        
        prefix = [0] * (maxi + 1)
        ans = []
        # total number of pairs
        total_pairs = 0

        for d in range(1, maxi + 1):
            total_pairs += pair[d] 
            prefix[d] = total_pairs
        
        for q in queries:
            # result that query corresponds to
            res = bisect_right(prefix,q)

            ans.append(res)

        return ans


        