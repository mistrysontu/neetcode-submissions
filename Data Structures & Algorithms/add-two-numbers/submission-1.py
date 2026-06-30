# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0

        ln1, ln2 = 0, 0
        t1, t2 = l1, l2
        while t1:
            ln1 += 1
            t1 = t1.next
        while t2:
            ln2 += 1
            t2 = t2.next
        # print(ln1 , ln2, ln2 > ln1)
        if ln2 > ln1:
            l1, l2 = l2, l1
        res = l1
        end = None
        while True:
            if not l1 or not l2:
                break
            # print(l1.val, l2.val, carry)
            sm = (l1.val + l2.val + carry)
            l1.val = sm % 10
            carry = sm // 10
            if not l1.next:
                end = l1
            l1, l2 = l1.next, l2.next
        while l1:
            sm = (l1.val + carry)
            l1.val = sm % 10
            carry = sm // 10
            if not l1.next:
                end = l1
            l1 = l1.next
        
        if carry:
            nw = ListNode(carry)
            end.next = nw

        return res


