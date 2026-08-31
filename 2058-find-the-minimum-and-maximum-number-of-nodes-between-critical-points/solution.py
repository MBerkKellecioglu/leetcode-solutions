# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        
        ans = [float("inf"), float("-inf")]

        prev = head
        curr = head.next

        idx = 1

        f,l,p = -1,-1,-1 # first, last and prev idx of critical points

        while curr.next != None:
            nxt = curr.next
            if (prev.val < curr.val and curr.val > nxt.val) or (prev.val > curr.val and curr.val < nxt.val):
                if f == -1:
                    f = idx
                    p = idx
                else:
                    l = idx
                    ans[0] = min(ans[0], idx - p)
                    p = idx
            
            idx += 1
            prev = curr
            curr = curr.next
        
        if f == -1 or l == -1:
            return [-1,-1]

        ans[1] = (l - f)

        return ans