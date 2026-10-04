class Solution:
    def countInterestingSubarrays(self, nums: list[int], modulo: int, k: int) -> int:
        
        ans = 0
   
        indexes = {0: 1}

        interesting = 0
        
        for num in nums:

            if num % modulo == k:
                interesting += 1
            
            current_mod = interesting % modulo
    
            needed_mod = (current_mod - k + modulo) % modulo
 
            if needed_mod in indexes:
                ans += indexes[needed_mod]
        
            if current_mod in indexes:
                indexes[current_mod] += 1
            else:
                indexes[current_mod] = 1
                
        return ans