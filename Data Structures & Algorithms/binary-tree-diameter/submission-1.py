# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ret = 0
        def getDiameter(node):
            nonlocal ret 
            if not node:
                return 0
            l, r = getDiameter(node.left), getDiameter(node.right)
            ret = max(ret, l+r)
            return 1 + max(l, r)
        getDiameter(root)

        return ret
