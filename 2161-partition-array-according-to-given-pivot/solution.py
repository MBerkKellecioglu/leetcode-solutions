class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        
        lesser = []
        
        equal = 0

        greater = []

        for num in nums:
            if pivot < num:
                greater.append(num)
            elif pivot == num:
                equal += 1
            else:
                lesser.append(num)

        return lesser + [pivot] * equal + greater