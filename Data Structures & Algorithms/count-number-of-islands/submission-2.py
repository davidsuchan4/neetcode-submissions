class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        queue = deque()
        islands = 0
        dirs = [
            [1,0],[0,1],[-1,0],[0,-1]
        ]
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == "1":
                    queue.append([r, c])
                    grid[r][c] = "2"
                    while queue:
                        r, c = queue.popleft()
                        for dir in dirs:
                            newR = r + dir[0]
                            newC = c + dir[1]
                            if newC >= 0 and newC < len(grid[0]) and newR >= 0 and newR < len(grid):
                                if grid[newR][newC] == "1":
                                    queue.append([newR, newC])
                                    grid[newR][newC] = "2"

                    islands += 1
        return islands

                            

                

