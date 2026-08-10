class Solution:
    def floodFill(self, image, sr, sc, color):

        old_color = image[sr][sc]

        if old_color == color:
            return image

        def dfs(row, col):

            if row < 0 or row >= len(image):
                return

            if col < 0 or col >= len(image[0]):
                return

            if image[row][col] != old_color:
                return

            image[row][col] = color

            dfs(row - 1, col)  # up
            dfs(row + 1, col)  # down
            dfs(row, col - 1)  # left
            dfs(row, col + 1)  # right

        dfs(sr, sc)

        return image