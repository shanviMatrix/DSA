class Solution:
    def numIslands(self, grid):

        rows = len(grid)
        cols = len(grid[0])

        count = 0

        def dfs(row, col):

            if row < 0 or row >= rows:
                return

            if col < 0 or col >= cols:
                return

            if grid[row][col] == "0":
                return

            grid[row][col] = "0"

            dfs(row - 1, col)  # up
            dfs(row + 1, col)  # down
            dfs(row, col - 1)  # left
            dfs(row, col + 1)  # right

        for row in range(rows):
            for col in range(cols):

                if grid[row][col] == "1":

                    count += 1

                    dfs(row, col)

        return count