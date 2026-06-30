# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def helper(self, root, balanced=True):
        left = 0
        right = 0
        b1 = True
        b2 = True
        if not root:
            return 0, balanced and True
        if root.left:
            left, b1 = self.helper(root.left, balanced)
        if root.right:
            right, b2 = self.helper(root.right, balanced)
        
        balanced = (abs(left-right) <= 1) and b1 and b2
        return 1 + max(left, right), balanced       

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root)[1]