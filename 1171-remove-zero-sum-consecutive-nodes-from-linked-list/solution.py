 # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: ListNode | None) -> ListNode | None:
        
        prefix = defaultdict(lambda: None)

        total = 0

        dummy = ListNode()

        prefix[total] = dummy

        curr = head
        dummy.next = head

        while curr != None:
            total += curr.val

            if prefix[total] != None:
                start = prefix[total]

                tmp = start.next
                tmp_total = total

                while tmp != curr:
                    tmp_total += tmp.val
                    del prefix[tmp_total]
                    tmp = tmp.next

                start.next = curr.next
                curr.next = None

                curr = start
            else:
                prefix[total] = curr
            
            curr = curr.next
        
        return dummy.next
        