# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return isValidBSTHelper(root, float('-inf'), float('inf'))

def isValidBSTHelper(node, low, high):
    if not node:
        return True
    if not (low < node.val < high):
        return False
    return (isValidBSTHelper(node.left, low, node.val) and
            isValidBSTHelper(node.right, node.val, high))
