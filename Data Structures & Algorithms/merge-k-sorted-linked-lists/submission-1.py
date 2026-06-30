# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        def mergeLL(l1, l2):
            temp = ListNode()
            res = temp
            while True:
                v1 = l1.val if l1 else float('inf')
                v2 = l2.val if l2 else float('inf')
                if v1 == float('inf') and v2 == float('inf'):
                    break
                if v1 < v2:
                    temp.next = l1
                    l1 = l1.next
                else:
                    temp.next = l2
                    l2 = l2.next
                temp = temp.next
            return res.next

        if lists is None or not len(lists):
            return None

        while len(lists) > 1:
            # devide the lists in (n/2) smaller block and merge them into (n/4) bolcks
            # continue until only one element left
            tempList = []
            print(lists)
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if i+1 < len(lists) else None
                mergedList = mergeLL(l1, l2)
                tempList.append(mergedList)
            lists = tempList
        return lists[0]