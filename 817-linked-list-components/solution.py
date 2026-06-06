# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        
        curr = head
        flag = False

        comp = [False] * (10**4 + 1)

        ans = 0

        for num in nums:
            comp[num] = True
        
        while curr:
            if flag:
                if not comp[curr.val]:
                    flag = False
            else:
                if comp[curr.val]:
                    flag = True
                    ans += 1
            
            curr = curr.next

        return ans


        