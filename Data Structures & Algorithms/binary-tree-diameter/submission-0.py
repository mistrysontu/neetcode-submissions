# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def helper(self, root, length):
        left = 0
        right = 0
        if not root:
            return 0, 0
        if root.left:
            left = 1 + self.helper(root.left, length)[1]
        if root.right:
            right = 1 + self.helper(root.right, length)[1]

        length = max(length, (left + right))
        return length, max(left, right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.helper(root, 0)[0]