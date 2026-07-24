class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:

        def isMirror(left_node, right_node):

            if left_node is None and right_node is None:
                return True

            if left_node is None or right_node is None:
                return False

            if left_node.val != right_node.val:
                return False

            return (
                isMirror(left_node.left, right_node.right)
                and
                isMirror(left_node.right, right_node.left)
            )

        return isMirror(root.left, root.right)