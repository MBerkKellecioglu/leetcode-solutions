class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        
        maxi, ans = max(costs), 0 

        nums = [0] * (maxi + 1)
        srt = [0] * len(costs)

        for cost in costs:
            nums[cost] += 1
        
        prev = nums[0]
        nums[0] = 0

        for i in range(1, maxi + 1):
            nums[i], prev = prev, nums[i]
            prev += nums[i]

        for cost in costs:
            srt[nums[cost]] = cost
            nums[cost] += 1
        
        for cost in srt:
            if coins >= cost:
                ans += 1
                coins -= cost
            else:
                break
        
        return ans