# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        idx = 0
        flag = True
        val = -101
        def helper(node):
            nonlocal idx, flag, val
            if val != -101:
                return
            if flag and not node.left:
                idx = 1
                flag = False
            if node.left:
                helper(node.left)
            print(node.val, idx)
            if idx == k:
                # print('hi')
                val = node.val
            idx += 1
            if node.right:
                helper(node.right)

        if not root:
            return -1
        helper(root)
        return val

        
        