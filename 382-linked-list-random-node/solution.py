# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head

    def getRandom(self) -> int:
        
        curr = self.head
        sample = 1
        
        ans = curr.val
        
        curr = curr.next
        
        while curr != None:
            sample += 1
            
            if randint(1,sample) == sample:
                ans = curr.val
            
            curr = curr.next
        
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()