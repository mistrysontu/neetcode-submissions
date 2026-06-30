# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        _map = {}

        def helper(node, level):
            if level in _map:
                _map[level].append(node.val)
            else:
                _map[level] = [node.val]
            
            if node.left:
                helper(node.left, level+1)
            if node.right:
                helper(node.right, level+1)

        res = []
        if not root:
            return res
            
        helper(root, 0)
        for i in range(10):
            if i not in _map:
                break
            res.append(_map[i])
        
        return res
            


