# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def depth(self, root):
        left = 0
        right = 0
        if not root:
            return left
        if root.left:
            left =  self.depth(root.left)
        if root.right:
            right = self.depth(root.right)

        return 1 + max(left, right)
        
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.depth(root)