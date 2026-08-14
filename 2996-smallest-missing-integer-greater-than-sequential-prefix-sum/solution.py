class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        
        check = defaultdict(int)

        idx, total = 0, nums[0]

        while idx + 1 < len(nums):
            if nums[idx + 1] == nums[idx] + 1:
                total += nums[idx + 1]
                idx += 1
            else:
                break

        for i in range(len(nums)):
            check[nums[i]] += 1

        ans = total

        while 1:
            if check[total] == 0:
                return total
            else:
                total += 1
        
        return -1
        


            
