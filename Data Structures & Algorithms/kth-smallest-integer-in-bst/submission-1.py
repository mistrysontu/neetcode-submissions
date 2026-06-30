# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        inorder = []

        def helper(node):
            nonlocal inorder
            if node.left:
                helper(node.left)
            inorder.append(node.val)
            if len(inorder) >= k:
                return
            if node.right:
                helper(node.right)

            
        if not root:
            return -1
        
        helper(root)

        return inorder[k-1]
        