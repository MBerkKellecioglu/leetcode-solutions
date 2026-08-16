# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        curr = head
        
        nums = []
        
        while curr != None:
            nums.append(curr.val)
            curr = curr.next
        
        n = len(nums)
            
        for i in range(n // 2):
            if nums[i] != nums[n - 1 - i]:
                return False
        
        return True
            
            
            
        