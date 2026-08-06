class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:

        result = []

        def dfs(node, path):

            if node is None:
                return

            path += str(node.val)

            if node.left is None and node.right is None:
                result.append(path)
                return

            path += "->"

            dfs(node.left, path)

            dfs(node.right, path)

        dfs(root, "")

        return result