# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        prev = ListNode(-1,head)
        curr = head
        
        start = prev
        
        while curr != None:
            if curr.val == val:
                prev.next = curr.next
                curr.next = None
                curr = prev.next
            else:
                prev = prev.next
                curr = curr.next
        
        return start.next
        