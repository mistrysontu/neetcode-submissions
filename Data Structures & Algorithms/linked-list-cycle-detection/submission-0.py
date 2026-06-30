# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head.val == 1001:
            return True
        head.val = 1001
        if head.next:
            return self.hasCycle(head.next)
        return False