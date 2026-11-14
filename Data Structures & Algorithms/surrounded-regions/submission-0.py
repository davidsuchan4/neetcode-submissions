class Solution:
    def solve(self, board: List[List[str]]) -> None:
        rows = len(board)
        columns = len(board[0])

        dirs = [
            [1,0],[0,1],[-1,0],[0,-1]
        ]

        def dfs(r, c):
            board[r][c] = "#"

            for dir in dirs:
                newR = r + dir[0]
                newC = c + dir[1]
                if newR < rows and newR >= 0 and newC < columns and newC >= 0 and board[newR][newC] == "O":
                    board[newR][newC] = "#"
                    dfs(newR, newC)

        for r in range(rows):
            if board[r][0] == "O":
                dfs(r, 0)
            if board[r][columns - 1] == "O":
                dfs(r, columns - 1)
        for c in range(columns):
            if board[0][c] == "O":
                dfs(0, c)
            if board[rows - 1][c] == "O":
                dfs(rows - 1, c)
        
        for row in board:
            for c, cell in enumerate(row):
                if cell == "O":
                    row[c] = "X"
                elif cell == "#":
                    row[c] = "O"