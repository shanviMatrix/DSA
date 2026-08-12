class Solution:
    def maxDepth(self, root):

        if root is None:
            return 0

        maximum = 0

        for child in root.children:
            depth = self.maxDepth(child)

            if depth > maximum:
                maximum = depth

        return maximum + 1