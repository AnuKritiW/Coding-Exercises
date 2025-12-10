# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.ans = 0 

        def depth(root: Optional['TreeNode']) -> int:
            if not root:
                return 0
            L = depth(root.left)
            R = depth(root.right)

            self.ans = max(self.ans, L + R) # update diameter

            return 1 + max(L, R) # return height from this node down

        depth(root)
        return self.ans