# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # use slow and fast pointer concept
        res = head
        slow, fast = head, head
        flag = True
        # next step need to be performed in a loop
        up = None
        while slow and fast:
            start = slow
            n = k
            while n:
                # handle the case where you don't have k elements
                if not fast:
                    return res
                fast = fast.next
                n -= 1

            # reverse all the nodes in b/w slow and fast pointer
            prev, nxt = fast, slow
            while slow != fast:
                if not slow:
                    break
                print('curr ', slow.val)
                nxt = slow.next
                slow.next = prev
                prev = slow
                slow = nxt
            if flag:
                res = prev
                flag = False
            if up:
                print('hi')
                up.next = prev
            up = start
            print('start ', start.val)
            print('\n')
            # print(slow.val, fast.val)

        return res