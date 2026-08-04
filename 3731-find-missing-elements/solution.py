class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        
        mini,maxi = min(nums),max(nums)
        
        check = defaultdict(int)
        
        ans = []
        
        for num in nums:
            check[num] = 1
        
        for i in range(mini + 1,maxi):
            if check[i] == 0:
                ans.append(i)
        
        
        return ans
            