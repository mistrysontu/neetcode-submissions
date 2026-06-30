# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # count number of nodes
        temp = head
        noOfNodes = 0
        while temp:
            noOfNodes += 1
            temp = temp.next
        if noOfNodes <= 1:
            return head
        half = math.ceil(noOfNodes / 2)

        # devide the list into two almost equal part
        tail = head
        temp = None
        while half:
            if half == 1:
                temp = tail
            tail = tail.next
            half -= 1
        temp.next = None

        # reverse 2nd list
        prev, curr, nxt = None, tail, tail.next
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        tail = prev


        res = dummy = ListNode()
        flipFlop = 1

        while True:
            if flipFlop % 2 == 1 :
                print('flip ', head.val)
                dummy.next = head
                head = head.next
            else:
                print('flop', tail.val)
                dummy.next = tail
                tail = tail.next
                # print('fgp ', tail.val)
            dummy = dummy.next
            print('ff ',flipFlop)
            if tail == None:
                break
            flipFlop += 1
        
        dummy.next = head

        return res.next
        
        