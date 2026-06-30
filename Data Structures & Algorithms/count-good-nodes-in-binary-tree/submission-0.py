# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        cnt = 0
        if not root:
            return cnt
        
        def helper(node, bigSoFar):
            nonlocal cnt
            if not node:
                return
            if node.val >= bigSoFar:
                cnt += 1
            if node.left:
                helper(node.left, max(bigSoFar, node.val))
            if node.right:
                helper(node.right, max(bigSoFar, node.val))

        helper(root, -101)
        return cnt


        