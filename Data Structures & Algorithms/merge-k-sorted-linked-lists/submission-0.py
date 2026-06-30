# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        tempList = [i for i in lists]
        # idx = None
        dummy = res = ListNode()
        while True:
            val = float('inf')
            idx = None
            cnt = 0
            for i, e  in enumerate(tempList):
                if e:
                    if e.val < val:
                        val = e.val
                        idx = i
                else:
                    cnt += 1
            if cnt == len(lists):
                break
            node = ListNode(val)
            dummy.next = node
            dummy = dummy.next
            tempList[idx] = tempList[idx].next
        return res.next

