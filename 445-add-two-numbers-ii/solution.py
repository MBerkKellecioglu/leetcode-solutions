# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        total1, total2 = 0,0
        
        curr1,curr2 = l1,l2
        
        while curr1:
            total1 = total1 * 10 + curr1.val
            
            curr1 = curr1.next
        
        while curr2:
            total2 = total2 * 10 + curr2.val
            
            curr2 = curr2.next
        
        total = total1 + total2
        
        ans = ListNode()
        
        curr = ans
        
        total = str(total)
        
        for i in range(len(total)):
            curr.val = int(total[i])
            if i < len(total) - 1:
                curr.next = ListNode()
                curr = curr.next
        
        return ans
        
        