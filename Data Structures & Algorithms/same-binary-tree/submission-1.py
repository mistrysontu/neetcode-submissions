# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def helper(self, root, arr = []):
        if not root:
            return [None]
        if root.left:
            self.helper(root.left, arr)
        else:
            arr.append(None)
        if root.right:
            self.helper(root.right, arr)
        else:
            arr.append(None)
        arr.append(root.val)
        return arr

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        print(self.helper(p, []))
        print(self.helper(q, []))

        return self.helper(p, []) == self.helper(q, [])