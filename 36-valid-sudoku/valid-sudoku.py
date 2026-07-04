class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue

                number = board[i][j]
                box = (i // 3) * 3 + (j // 3)

                if number in rows[i]:
                    return False

                if number in cols[j]:
                    return False

                if number in boxes[box]:
                    return False

                rows[i].add(number)
                cols[j].add(number)
                boxes[box].add(number)

        return True