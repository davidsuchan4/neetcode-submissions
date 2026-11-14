class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rSize = len(heights)
        cSize = len(heights[0])
        dirs = [
            [0,1],[1,0],[0,-1],[-1,0]
        ]
        ret = []
        reachableP = set()
        reachableA = set()
        def dfs(r, c, ocean):
            reachable = reachableP if ocean == 'P' else reachableA
            if (r, c) in reachable:
                return
            if ocean == 'P':
                reachableP.add((r, c))
            else:
                reachableA.add((r, c))
            for dir in dirs:
                newR = r + dir[0]
                newC = c + dir[1]
                if newR < rSize and newR >= 0 and newC < cSize and newC >= 0 and heights[newR][newC] >= heights[r][c]:
                    dfs(newR, newC, ocean)


        for c in range(cSize):
            dfs(0, c, 'P')
            dfs(rSize - 1, c, 'A')

        for r in range(rSize):
            dfs(r, 0, 'P')
            dfs(r, cSize - 1, 'A')
        
        for cell in reachableP:
            if cell in reachableA:
                ret.append(list(cell))


        return ret
                    
        