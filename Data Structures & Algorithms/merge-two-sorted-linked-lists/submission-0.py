# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
1 2 4
5, 6, 8
'''

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        d1, d2 = ListNode(), ListNode()
        res = d1
        d1.next = list1
        d2.next = list2

        while True:
            if not d2.next:
                return res.next
            if not d1.next:
                d1.next = d2.next
                return res.next
            if d1.next.val > d2.next.val:
                temp = d2.next
                d2.next = d2.next.next
                temp.next = d1.next
                d1.next = temp
            d1 = d1.next
            
            