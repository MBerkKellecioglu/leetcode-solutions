# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head or not head.next:
            return head

        curr = head.next
        prev = head

        while curr != None:
            if curr.val == prev.val:
                prev.next = curr.next
                curr.next = None
                curr = prev.next
            else:
                curr = curr.next
                prev = prev.next
        
        return head