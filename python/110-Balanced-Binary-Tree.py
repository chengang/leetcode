# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def height(self, node):
        if not node:
            return 0
        if not node.left and not node.right:
            return 1

        lh = self.height(node.left)
        rh = self.height(node.right)
        return max(lh, rh) + 1

    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        if not root.left and not root.right:
            return True
        else:
            lh = self.height(root.left)
            rh = self.height(root.right)
            flag = True
            if (lh - rh > 1 or rh - lh > 1):
                return False
            return flag and self.isBalanced(root.left) and self.isBalanced(root.right)
