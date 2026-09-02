class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        
        mini = float("inf")
        odd = False
        
        for num in nums1:
            mini = min(mini,num)
            odd |= (num % 2)
        
        if mini % 2:
            return True
        else:
            if not odd:
                return True
            
        
        return False