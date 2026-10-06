# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: ListNode | None) -> list[int]:
        
        stack = []

        curr, idx = head, 0

        ans = []

        while curr != None:
            while stack and curr.val > stack[-1][0]:
                _, i = stack.pop()
                ans[i] = curr.val
            else:
                stack.append((curr.val, idx))
                ans.append(0)

            idx += 1
            curr = curr.next
        
        return ans
