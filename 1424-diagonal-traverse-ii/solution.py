class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        
        ordered = []

        ans = []

        n = len(nums)

        for i in range(n):
            for j in range(len(nums[i])):
                ordered.append((i + j, i, nums[i][j]))
        
        ordered.sort(key = lambda x : (x[0], -x[1]))

        for _,_,val in ordered:
            ans.append(val)
        
        return ans
        

