# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        balanced = True

        def helper(node):
            nonlocal balanced
            if not node:
                balanced = balanced and True
                return 0
            l, r = helper(node.left), helper(node.right)
            balanced = balanced and (abs(l - r) <= 1)
            return 1 + max(l, r)

        helper(root)        
        return balanced
        