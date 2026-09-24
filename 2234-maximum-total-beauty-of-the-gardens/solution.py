class Solution:
    def maximumBeauty(self, flowers: list[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        
        n, ans = len(flowers), 0

        incomplete_gardens = []

        complete_gardens = 0

        # count gardens that has more flowers than target already and add incomplete gardens to our array
        for flower in flowers:
            if flower < target:
                incomplete_gardens.append(flower)
            else:
                complete_gardens += 1
            
        m = len(incomplete_gardens)
        
        # if no incomplete gardens
        if m == 0:
            return full * n

        incomplete_gardens.sort()

        prefix = [0] * (m + 1)

        for i in range(m):
            prefix[i + 1] = prefix[i] + incomplete_gardens[i]
        
        # complete here represents number of gardens to complete 
        for complete in range(m + 1):
            # total number of flowers of the gardens which we want to complete
            curr_total_flowers = (prefix[m] - prefix[m - complete]) 

            flowers_needed = (complete * target) - (curr_total_flowers) 

            # if count of flowers that we need exceeds flowers that we cant make more gardens complete so we break
            if flowers_needed > newFlowers:
                break
            
            # number of incomplete gardens after we completed "complete (variable name)" amount of gardens
            remaining_gardens = m - complete

            # remaining flowers that we will distribute among other incomplete gardens
            remaining_flowers = newFlowers - flowers_needed

            # maximum minimum flowers among incomplete gardens
            max_min = incomplete_gardens[0]

            # our current beauty value is already completed gardens and gardens that we completed in this loop
            curr_beauty = (complete_gardens + complete) * full

            if remaining_gardens > 0:
                # we binary search to find maximum of minimum flowers among incomplete gardens
                l = incomplete_gardens[0]
                r = target - 1

                while l <= r:
                    mid = (l + r) // 2

                    # this idx is to find which elements are lower than mid so we can add flowers to them 
                    idx = bisect_left(incomplete_gardens,mid,0,remaining_gardens)

                    # if we have enough flowers to raise all garden flower levels to mid then curr max_min is mid
                    if (idx * mid) - prefix[idx] <= remaining_flowers:
                        max_min = mid
                        l = mid + 1
                    else:
                        r = mid - 1
                
                curr_beauty += (max_min * partial)
            
            ans = max(ans,curr_beauty)

        return ans


        
