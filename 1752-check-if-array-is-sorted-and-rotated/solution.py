class Solution:
    def check(self, nums: List[int]) -> bool:
        
        n = len(nums)

        for i in range(n):
            flag = True
            for j in range(i, i + n - 1):
                if nums[j % n] > nums[(j + 1) % n]:
                    flag = False
                    break
            
            if flag:
                return True

        return False